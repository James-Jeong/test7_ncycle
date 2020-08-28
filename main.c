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
 * @brief 숫자 자리수가 2 인지 검사하는 함수
 * @param value 자리수를 검사할 숫자
 * @return 두 자리수이면 YES, 아니면 NO 반환 
 */
int checkNumberIs2digit(int value)
{
	int secondDigit = value / 10;
	return (secondDigit > 0 && secondDigit < 10) ? YES : NO;
}

/**
 * @fn void makeNumber2digits(char *buf, int value)
 * @brief 두 자리수 숫자를 문자열로 변환하는 함수
 * @param buf 문자열을 저장하는 버퍼
 * @param value 최대 두 자리의 숫자
 * @return 반환값 없음
 */
void makeNumber2digits(char *buf, int value)
{
	buf[0] = '\0';
	if(checkNumberIs2digit(value) == YES)
	{
		sprintf(buf, "%d", value);
	}
	else sprintf(buf, "0%d", value);
}

/////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////

/**
 * @fn void main()
 * @brief 메인 함수
 * @return 반환값 없음
 */
void main()
{
	int checkInputIsNumber = NO;
	int value = 0;

	// input_number
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

	// caculate
	int tempValue = value;
	int cycleCount = 0;
	int sumOfDigits = 0;
	int concatOfRightDigits = 0;

	char firstInput[2];
	char firstDigitSum[2];
	char secondDigitSum[2];

	while(1){
		makeNumber2digits(firstInput, tempValue);

		sumOfDigits = (firstInput[0] - '0') + (firstInput[1] - '0');
		printf("(%d) + (%d) = %d(a)\n", (firstInput[0] - '0'), (firstInput[1] - '0'), sumOfDigits);

		makeNumber2digits(firstDigitSum, sumOfDigits);

		secondDigitSum[0] = firstInput[1];
		secondDigitSum[1] = firstDigitSum[1];

		concatOfRightDigits = atoi(secondDigitSum);
		printf("%d(b)\n", concatOfRightDigits);

		cycleCount++;

		if(concatOfRightDigits != value)
		{
			printf("Not equal, restart\n");
			tempValue = concatOfRightDigits;
		}
		else
		{
			printf("Equal! : %d == %d\n", value, concatOfRightDigits);
			break;
		}
	}

	printf("\n%d\n", cycleCount);
}

