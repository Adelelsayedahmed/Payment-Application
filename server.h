/*
* ************ Author	: Adel Elsayed		****************
* ************ Date		: August 2022			****************
* ************ SWC		: Server.h			****************
*/
#ifndef SERVER_H_
#define SERVER_H_
#include "terminal.h"
#define MAX_ACCOUNTS_NUMBER		255
typedef enum
{
	APPROVED,
    DECLINED_INSUFFECIENT_FUND,
    DECLINED_STOLEN_CARD,
    INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum
{
	SOK,
    SAVING_FAILED,
    TRANSACTION_NOT_FOUND,
    ACCOUNT_NOT_FOUND,
    LOW_BALANCE
}EN_serverError_t;

typedef struct
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef struct
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_transState_t recieveTransactionData(ST_transaction_t* transData);

#endif
