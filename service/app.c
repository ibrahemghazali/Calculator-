/*
 * app.c
 *
 * Created: 4/17/2026 9:25:28 PM
 *  Author: ibrah
 */ 

#include "app.h"

uint8 is_operator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

uint8 validate_syntax(char *ptr)
{
	uint8 i = 0;
	
	if(is_operator(ptr[0]))
	return 0;

	while(ptr[i] != '\0')
	{
		if(is_operator(ptr[i]))
		{
			
			if(ptr[i+1] == '\0')
			return INVALID_SYNTAX;

			if(is_operator(ptr[i+1]))
			return 0;
		}
		i++;
	}

	return VALID_SYNTAX; // valid
}




void syntax_edit(char *ptr)
{
	uint8 local_counter=0;
	uint8 counter_2=0;
	uint8 position_save=0;
	char local_arr[3];
	while(ptr[local_counter]!='\0')
	{
		local_arr[0]=0;
		local_arr[1]=0;
		local_arr[2]=0;
		position_save=local_counter;
		while((ptr[local_counter]!='+')&&(ptr[local_counter]!='*')&&(ptr[local_counter]!='/')&&(ptr[local_counter]!='-')&&(ptr[local_counter]!='\0'))
		{
			local_arr[counter_2]=ptr[local_counter];
			counter_2++;
			local_counter++;
		}
		ptr[position_save]=convert_to_number(local_arr);
		while((ptr[position_save]!='+')&&(ptr[position_save]!='*')&&(ptr[position_save]!='/')&&(ptr[position_save]!='-')&&(ptr[position_save]!=0))
		{
			if(ptr[position_save]>='0'&&ptr[position_save]<='9')
			{
				ptr[position_save]=0;
			}
			position_save++;
		}
		local_counter++;
		counter_2=0;
	}
	
	local_counter=0;
	for(counter_2=0;counter_2<5;counter_2++)
	{
		for(local_counter=0;local_counter<50;local_counter++)
		{
			if(ptr[local_counter]==0)
			{
				for(local_counter=local_counter;local_counter<50;local_counter++)
				{
					ptr[local_counter]=ptr[local_counter+1];
				}
			}
		}
	}
}

uint8 convert_to_number(char *ptr)
{
	uint8 local_counter=0;
	uint8 result=0;
	while((ptr[local_counter]>='0')&&(ptr[local_counter]<='9'))
	{
		result=result*10+(ptr[local_counter]-'0');
		local_counter++;
	}
	return result;
}

void multiplication_division(char *ptr)
{
	uint8 counter_1=0;
	uint8 counter=0;
	uint8 counter_2=0;
	for(counter=0;counter<50;counter++)
	{
		if((ptr[counter]=='*')&&(ptr[counter+1]!='*'&&ptr[counter+1]!='/'))
		{
			ptr[counter+1]*=ptr[counter-1];
			ptr[counter]=0;
			ptr[counter-1]=0;
			// printf("counter+1=%i ptr=%i",counter+1,ptr[counter+1]);
		}
		else if((ptr[counter]=='/')&&(ptr[counter+1]!='*'&&ptr[counter+1]!='/'))
		{
			ptr[counter+1]=ptr[counter-1]/ptr[counter+1];
			ptr[counter]=0;
			ptr[counter-1]=0;
			//printf("counter+1=%i ptr=%i",counter+1,ptr[counter+1]);
		}
	}
	for(counter_2=0;counter_2<10;counter_2++)
	{
		for(counter_1=0;counter_1<50;counter_1++)
		{
			if(ptr[counter_1]==0)
			{
				for(counter_1=counter_1;counter_1<50;counter_1++)
				{
					ptr[counter_1]=ptr[counter_1+1];
				}
			}
		}
	}
}


void addtion_subtraction(char *ptr)
{
	uint8 counter=0;
	uint8 counter_1=0;
	uint8 counter_2=0;
	for(counter=0;counter<50;counter++)
	{
		if((ptr[counter]=='+')&&(ptr[counter+1]!='+'&&ptr[counter+1]!='-'))
		{
			ptr[counter+1]+=ptr[counter-1];
			ptr[counter]=0;
			ptr[counter-1]=0;
			//printf("counter+1=%i ptr=%i",counter+1,ptr[counter+1]);
		}
		else if((ptr[counter]=='-')&&(ptr[counter+1]!='+'&&ptr[counter+1]!='-'))
		{
			ptr[counter+1]=ptr[counter-1]-ptr[counter+1];
			ptr[counter]=0;
			ptr[counter-1]=0;
			//printf("counter+1=%i ptr=%i",counter+1,ptr[counter+1]);
		}
	}
	for(counter_2=0;counter_2<10;counter_2++)
	{
		for(counter_1=0;counter_1<50;counter_1++)
		{
			if(ptr[counter_1]==0)
			{
				for(counter_1=counter_1;counter_1<50;counter_1++)
				{
					ptr[counter_1]=ptr[counter_1+1];
				}
			}
		}
	}


}