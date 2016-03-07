/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.
ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isDateValid(int dd,int mm,int yyyy){
	if (mm == 2){
		if (yyyy % 4 == 0 && dd <= 29)
				return 1;
		else if (dd <= 28)
			return 1;
	}
	else if (mm >= 1 && mm <= 7){
		if (mm % 2 == 1 && dd <= 31)
			return 1;
		else if (dd <= 30)
			return 1;
	}
	else if (mm > 7 && mm <= 12){
		if (mm % 2 == 1 && dd>= 1 && dd <= 30)
			return 1;
		else if (dd >= 1 && dd <= 31)
			return 1;
	}
	return 0;
}

int isOlder(char *dob1, char *dob2) {
	int dd1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	int mm1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	int yyyy1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
    
	int dd2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	int mm2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	int yyyy2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
	
	//Date validation
	if (!(isDateValid(dd1, mm1, yyyy1) && isDateValid(dd2, mm2, yyyy2)))
		return -1;

	if (yyyy1 > yyyy2)
		return 2;
	else if (yyyy1 < yyyy2)
		return 1;
	else if (mm1>mm2)
		return 2;
	else if (mm1 < mm2)
		return 1;
	else if (dd1 > dd2)
		return 2;
	else if (dd1 < dd2)
		return 1;
	return 0;
}