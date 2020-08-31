#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////

// 조건 부합
#define YES			1
// 조건 부적합
#define NO			-1

/////////////////////////////////////////////////////////
// Local functions
/////////////////////////////////////////////////////////

/**
 * @fn int checkNumberIs2digit(int value)
 * @brief 정수 자리수가 2 인지 검사하는 함수
 * @param value 자리수를 검사할 정수
 * @return 두 자리수이면 YES, 아니면 NO 반환 
 */
int checkNumberIs2digit(int value)
{
	int secondDigit = value / 10;
	return (secondDigit > 0 && secondDigit < 10) ? YES : NO;
}

/**
 * @fn void makeNumber2digits(char *buf, int value)
 * @brief 두 자리수 정수를 문자열로 변환하는 함수
 * @param buf 문자열을 저장하는 버퍼
 * @param value 최대 두 자리의 정수
 * @return 반환값 없음
 */
void makeNumber2digits(char *buf, int value)
{
	if(buf == NULL)
	{
		printf("buf is NULL\n");
		return;
	}

	buf[0] = '\0';
	if(checkNumberIs2digit(value) == YES)
	{
		sprintf(buf, "%d", value);
	}
	else sprintf(buf, "0%d", value);
}

/**
 * @fn void calculateNCycle(int value)
 * @brief 정수의 자리수 덧셈 싸이클을 계산하는 함수
 * @param value 최대 두 자리의 정수
 * @return 반환값 없음
 */
void calculateNCycle(int value)
{
	int initialValue = value;
	int cycleCount = 0;
	int sumOfDigits = 0;
	int concatOfRightDigits = 0;

	char initialArray[2];
	char firstDigitSum[2];
	char secondDigitSum[2];

	while(1){
		makeNumber2digits(initialArray, initialValue);

		sumOfDigits = (initialArray[0] - '0') + (initialArray[1] - '0');
		printf("(%d) + (%d) = %d(a)\n", (initialArray[0] - '0'), (initialArray[1] - '0'), sumOfDigits);

		makeNumber2digits(firstDigitSum, sumOfDigits);

		secondDigitSum[0] = initialArray[1];
		secondDigitSum[1] = firstDigitSum[1];
		secondDigitSum[2] ='\0';

		concatOfRightDigits = atoi(secondDigitSum);
		printf("%d(b)\n", concatOfRightDigits);

		cycleCount++;

		if(concatOfRightDigits != value)
		{
			printf("Not equal, restart\n");
			initialValue = concatOfRightDigits;
		}
		else
		{
			printf("Equal! : %d == %d\n", value, concatOfRightDigits);
			break;
		}
	}

	printf("\n%d\n", cycleCount);
}

/////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////

/**
 * @fn void main()
 * @brief 메인 함수. 정수의 자리수 덧셈 싸이클을 계산하는 프로그램
 * @return 반환값 없음
 */
void main()
{
	int checkInputIsNumber = NO;
	int value = 0;

	while(1){
		printf("입력(0~99) : ");
		checkInputIsNumber = scanf(" %d", &value);
		if(checkInputIsNumber == NO)
		{
			printf("입력 실패. 문자열 입력됨!\n");
			continue;
		}
		else if((value < 0) || (value >= 100))
		{
			printf("입력 실패. 정수 입력 범위를 벗어남!\n");
			continue;
		}
		break;
	}

	calculateNCycle(value);
}

