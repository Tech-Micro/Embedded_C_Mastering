#include "C_Language/String_data.h"

static int convert_ascii_to_int(char *str);
static int convert_ascii_to_Byte(char *str);
static float convert_str_to_float(char *str);
static int find_len(char *str);

void Uart_Data()
{
	U02_Sensor_data();
	JSON_String_Format();
}


void U02_Sensor_data()
{
	char frame[]="*XD,0000,01,1234,00000,0030,5F19,1422#";

	int len = find_len(frame);       //int len=sizeof(frame);

	char word[8][10];

	int word_count=0,char_count=0;

	if( (len!=38) || frame[0]!='*' || frame[len-1] !='#')
	{
		printf("data frame error\n");
	}
	int i=1;
	while(frame[i] !='#')
	{
		if(frame[i]== ',')
		{
			word[word_count][char_count] = '\0';
			word_count++;
			char_count=0;
		}
		else
		{
			word[word_count][char_count] = frame[i];
			char_count++;
		}
		i++;
	}

	  word[word_count][char_count] = '\0';
	  word_count++;


	  for(int i=1;i<8;i++)
	  {
		  int temp=convert_ascii_to_Byte(word[i]);
		  if(i==6)
		  {
			  temp = ( (temp<<8)& 0xFF00 )| ((temp>>8)&0x00FF);
		  }
		  printf("value of frame of %d = %X\n",i+1,temp);
	  }
}



void JSON_String_Format()
{
	char frame[] = "{\"temp\":28.67,\"hum\":64,\"status\":\"OK\"}";

	char temp[10],hum[10],status[10];

	int i=0;
	int j=0;
	while(frame[i] !=':')
	{
		i++;
	}
	i++;
	while(frame[i] !=',')
	{
		temp[j++] = frame[i++];
	}
	temp[j] = '\0';

	j=0;
	while(frame[i] !=':')
	{
		i++;
	}
	i++;
	while(frame[i] !=',')
	{
		hum[j++] = frame[i++];
	}
	hum[j] = '\0';
	j=0;
	while(frame[i] !=':')
	{
		i++;
	}
	i++;
	i++;

	while(frame[i] !='"')
	{
		status[j++] = frame[i++];
	}
	status[j] = '\0';

	float Temperature = convert_str_to_float(temp);
	printf("Temperature = %.2f\n",Temperature);
	int Humidity = convert_ascii_to_int(hum);
	printf("Humidity = %d\n",Humidity);
	printf("Status = %s\n",status);


}


static int find_len(char *str)
{
	int i=0;
	while(str[i] !='\0')i++;

	return i;
}


static int convert_ascii_to_int(char *str)
{
	int i=0;
	int result=0;
	while(str[i] != '\0')
	{
		if(str[i] >= '0' &&  str[i] <= '9')
		{
			result = result*10+(str[i]-'0');
		}
		else
		{
			return -1;
		}
		i++;
	}
	return result;
}


static int convert_ascii_to_Byte(char *str)
{
	int i=0;
	int result=0;
	int byte=0;
	while(str[i] != '\0')
	{
		if(str[i] >= '0' &&  str[i] <= '9')
		{
			result = (str[i]-'0');
		}
		else if(str[i] >= 'A' &&  str[i] <= 'F')
		{
			result = (str[i]-'A')+10;
		}
		else if(str[i] >= 'a' &&  str[i] <= 'f')
		{
			result = (str[i]-'a')+10;
		}
		else
		{
			return -1;
		}

		byte = byte<<4 | result;

		i++;
	}
	return byte;
}


static float convert_str_to_float(char *str)
{
	int i=0;
	int isdecimal=0;
	float decimal=0.1f;
	float result=0;

	while(str[i] !='\0')
	{
		if(str[i] == '.')
		{
			isdecimal=1;
		}
		else if(isdecimal)
		{
			result = result+( (str[i] -'0' ) * decimal) ;
			decimal = decimal/10;
		}
		else if(str[i] >= '0' && str[i]<='9')
		{
			result = (result*10) + (str[i] - '0');
		}

		i++;
	}

	return result;
}
