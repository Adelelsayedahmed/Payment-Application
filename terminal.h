/*
* ************ Author	: Adel Elsayed		****************
* ************ Date		: August 2022			****************
* ************ SWC		: terminal.h		****************
*/
#ifndef TERMINAL_H_
#define TERMINAL_H_
#include "STD_TYPES.h"
#include "card.h"
typedef struct ST_terminalData_t
{
	uint8_t transactionDate[11];
	float maxTransAmount;
	float transAmount;
}ST_terminalData_t;

typedef enum
{
	TOK,
	WRONG_DATE,
    EXPIRED_CARD,
    INVALID_CARD,
    INVALID_AMOUNT,
    EXCEED_MAX_AMOUNT,
    INVALID_MAX_AMOUNT
}EN_terminalError_t;

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);


#endif
