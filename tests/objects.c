#include <unix.h>
#include <pkcs11.h>
#include <stdio.h>

#include "testlib.h"

#define ADD_CKO(cko) ckos[cko] = #cko

TEST_FUNC(objects) {
	CK_SESSION_HANDLE session;
	CK_OBJECT_HANDLE object;
	CK_ULONG count;
	CK_SLOT_ID slot;
	CK_ATTRIBUTE attr[2];
	CK_OBJECT_CLASS klass;
	char label[1024];
	char* ckos[8];
	int ret;
	ckrv_mod m[] = {
		{ CKR_OK, TEST_RV_FAIL },
		{ CKR_OPERATION_ACTIVE, TEST_RV_OK },
	};

	ADD_CKO(CKO_DATA);
	ADD_CKO(CKO_CERTIFICATE);
	ADD_CKO(CKO_PUBLIC_KEY);
	ADD_CKO(CKO_PRIVATE_KEY);
	ADD_CKO(CKO_SECRET_KEY);
	ADD_CKO(CKO_HW_FEATURE);
	ADD_CKO(CKO_DOMAIN_PARAMETERS);
	ADD_CKO(CKO_MECHANISM);

	check_rv(C_Initialize(NULL_PTR));

	if((ret = find_slot(CK_TRUE, &slot)) != TEST_RV_OK) {
		return ret;
	}

	check_rv(C_OpenSession(slot, CKF_SERIAL_SESSION, NULL_PTR, NULL_PTR, &session));

	check_rv(C_FindObjectsInit(session, NULL_PTR, 0));

	do {
		check_rv(C_FindObjects(session, &object, 1, &count));

		if(!count) continue;

		attr[0].type = CKA_CLASS;
		attr[0].pValue = &klass;
		attr[0].ulValueLen=sizeof(klass);
		
		attr[1].type = CKA_LABEL;
		attr[1].pValue = &label;
		attr[1].ulValueLen=1024;

		check_rv(C_GetAttributeValue(session, object, &attr, 2));

		label[attr[1].ulValueLen] = '\0';

		printf("Found object %lx (label: %s) of class %s (%#lx)\n", object, label, ckos[klass], klass);
		verbose_assert(klass == CKO_CERTIFICATE || klass == CKO_PUBLIC_KEY || klass == CKO_PRIVATE_KEY);
	} while(count);

	check_rv_long(C_FindObjectsInit(session, NULL_PTR, 0), m);

	check_rv(C_FindObjectsFinal(session));

	check_rv(C_CloseSession(session));

	check_rv(C_OpenSession(slot, CKF_SERIAL_SESSION, NULL_PTR, NULL_PTR, &session));

	check_rv(C_FindObjectsInit(session, NULL_PTR, 0));

	check_rv(C_CloseSession(session));

	check_rv(C_OpenSession(slot, CKF_SERIAL_SESSION, NULL_PTR, NULL_PTR, &session));

	check_rv(C_FindObjectsInit(session, NULL_PTR, 0));

	check_rv(C_CloseSession(session));

	check_rv(C_OpenSession(slot, CKF_SERIAL_SESSION, NULL_PTR, NULL_PTR, &session));

	if(have_robot()) {
		ckrv_mod m_maybe_rmvd[] = {
			{ CKR_TOKEN_NOT_PRESENT, TEST_RV_OK },
			{ CKR_DEVICE_REMOVED, TEST_RV_OK},
		};
		ckrv_mod m_is_rmvd[] = {
			{ CKR_OK, TEST_RV_FAIL },
			{ CKR_TOKEN_NOT_PRESENT, TEST_RV_OK },
			{ CKR_DEVICE_REMOVED, TEST_RV_OK },
		};
		ckrv_mod m_inv[] = {
			{ CKR_OK, TEST_RV_FAIL },
			{ CKR_DEVICE_REMOVED, TEST_RV_OK },	// really?!?
			{ CKR_SESSION_HANDLE_INVALID, TEST_RV_OK },
		};

		check_rv(C_FindObjectsInit(session, NULL_PTR, 0));

		robot_remove_card();

		check_rv_long(C_FindObjects(session, &object, 1, &count), m_maybe_rmvd);

		check_rv_long(C_GetAttributeValue(session, object, &attr, 1), m_is_rmvd);

		if((ret = find_slot(CK_TRUE, &slot)) != TEST_RV_OK) {
			return ret;
		}

		check_rv_long(C_FindObjectsInit(session, NULL_PTR, 0), m_inv);

		check_rv(C_CloseSession(session));

		check_rv(C_OpenSession(slot, CKF_SERIAL_SESSION, NULL_PTR, NULL_PTR, &session));

		check_rv(C_FindObjectsInit(session, NULL_PTR, 0));
	} else {
		printf("Robot not present, skipping card removal/insertion part of test...\n");
	}

	check_rv(C_Finalize(NULL_PTR));

	return TEST_RV_OK;
}