#include "login.h"


uint8 login()
{
	uint8 name[user_limit];
	uint8 pass[pass_limit];

	uint8 admin_check[user_limit];
	uint8 pass_admin_check[pass_limit];
	uint8 x[]={'-','-','-','-'};
	EEPROM_Read_Block_From_Address(200, admin_check, user_limit);
	EEPROM_Read_Block_From_Address(205,pass_admin_check , pass_limit);

	if(admin_check[0]==x[0]||EEPROM_Read_Byte_From_Address(200)==0xFF)
	{
		add_admin();
		LCD_Init();
		LCD_WriteString("added");
		LCD_Init();
		main();
	}
	else
	{

	LCD_WriteString("user name: ");

	for(int i=0 ;i< user_limit ;)
	{
		uint8 letter =get_char();
		_delay_ms(200);
		if(letter!='m'){
		LCD_WriteChar(letter);
		name[i]=letter;
		i++;
		}

	}

    LCD_GoTo(1, 0);
    LCD_WriteString("password: ");
    for(int i=0 ;i<pass_limit;)
    {
    	uint8 letter =get_char();
    	_delay_ms(200);
    	if(letter!='m'){
    	LCD_WriteChar(letter);
    	pass[i]=letter;
    	i++;

    }
    }
    if(name[0]==admin_check[0])
    		{
    			for(int i=0 ; i<user_limit ;)
    			{
    				if(name[i]==admin_check[i])
    				{

    					i++;
    					if(i==user_limit)
    					{

    						for(int j=0 ;j < pass_limit ;)
    						{

    							if(pass[j]==pass_admin_check[j])
    							{

    								j++;
    								if(j==pass_limit)
    								{
    									return 1;
    								}

    							}


    						}
    					}


    				}


    			}
    		}

   if(check1(&name, &pass))
   {
	  LCD_Init();
	  LCD_WriteString("login success");
	 // _delay_ms(500);
	  LCD_Init();
	   return 2;
   }

   else
   {
	   LCD_Init();
	   LCD_WriteString("wrong pass or user");
	   //_delay_ms(500);
	   LCD_Init();
	   return 0;
   }



}
}

void add_user1()
{


LCD_Init();
	static uint16 count=0;




	 if(EEPROM_Read_Byte_From_Address(85)>0&&EEPROM_Read_Byte_From_Address(85)<=10)
	 {
		count= EEPROM_Read_Byte_From_Address(85);
	 }
	 else
	 {
		 count=0;
	 }



	 uint8 erase_count =EEPROM_Read_Byte_From_Address(90);




	uint8 name1[user_limit];
	uint8 pass[pass_limit];

	static uint16 numUsers=0;
	static uint16 numPass=41;
	 if(erase_count>0&&erase_count<=10)
	 {
		 uint16 numUsers_d=0;
		 uint16 numPass_d=41;

			for(;numUsers_d<41;)
			{
				uint8 arr[user_limit];
				uint8 arr_pass[pass_limit];
				EEPROM_Read_Block_From_Address(numUsers_d,arr , user_limit);
				EEPROM_Read_Block_From_Address(numPass_d,arr_pass , pass_limit);


						if(arr[0]=='-')
						{

							numUsers=numUsers_d;
							numPass=numPass_d;
							erase_count--;
							EEPROM_Write_Byte_To_Address(90, erase_count);
							LCD_WriteString("done");
							break;
						}


				numUsers_d+=4;
				numPass_d+=4;
			}


	 }
	 else
	 {
		 numUsers =numUsers+(4*count);
		 numPass=numPass+(4*count);
	 }



	LCD_WriteString("user name: ");

	for(int i=0 ;i< user_limit ;)
	{
		uint8 letter =get_char();
				_delay_ms(200);
				if(letter!='m'){
				LCD_WriteChar(letter);
				name1[i]=letter;
				i++;
				}
	}



    LCD_GoTo(1, 0);
    LCD_WriteString("password: ");
    for(int i=0 ;i<pass_limit;)
    {
    	uint8 letter =get_char();
    	    	_delay_ms(200);
    	    	if(letter!='m'){
    	    	LCD_WriteChar(letter);
    	    	pass[i]=letter;
    	    	i++;

       }
    }

    if(check_exist(name1, pass))
    {
        EEPROM_Write_Block_To_Address(numUsers, name1 ,user_limit);
    	EEPROM_Write_Block_To_Address(numPass, pass ,pass_limit);
        numUsers+=4;
        numPass+=4;
        count++;
        EEPROM_Write_Byte_To_Address(85, count);
    }
    else
    {
    	LCD_Init();
    	LCD_WriteString("antother one");
    	LCD_Init();
    	add_user1();

    }



}

uint8 check1(uint8 name[],uint8 pass[])
{
	 uint16 numUsers=0;
	 uint16 numPass=41;

	for(;numUsers<41;)
	{
		uint8 arr[user_limit];
		uint8 arr_pass[pass_limit];
		EEPROM_Read_Block_From_Address(numUsers,arr , user_limit);
		EEPROM_Read_Block_From_Address(numPass,arr_pass , pass_limit);
		if(arr[0]==name[0])
		{
			for(int i=0 ; i<user_limit ;)
			{
				if(arr[i]==name[i])
				{

					i++;
					if(i==user_limit)
					{
						for(int j=0 ;j < pass_limit ;)
						{
							if(pass[j]==arr_pass[j])
							{
								j++;
								if(j==pass_limit)
								{
									return 1;
								}
							}
							else
							{
								return 0;
							}

						}
					}

				}
				else
				{
					return 0;
				}

			}
		}
		numUsers+=4;
		numPass+=4;
	}
	return 0;


}

void delete_user(uint8 name[])
{
	 uint16 numUsers=0;
	 uint16 numPass=41;
	 uint8 arr_deleted[4]={'-','-','-','-'};
	 static uint8 erase=0;
	 if(EEPROM_Read_Byte_From_Address(90)>0&&EEPROM_Read_Byte_From_Address(90)<=10)
		 {
			erase= EEPROM_Read_Byte_From_Address(90);
		 }
		 else
		 {
			 erase=0;
			 EEPROM_Write_Byte_To_Address(90, erase);
		 }





		for(;numUsers<41;)
		{
			uint8 arr[user_limit];
			uint8 arr_pass[pass_limit];
			EEPROM_Read_Block_From_Address(numUsers,arr , user_limit);
			EEPROM_Read_Block_From_Address(numPass,arr_pass , pass_limit);
			if(arr[0]==name[0])
			{
				for(int i=0 ; i<user_limit ;)
				{
					if(arr[i]==name[i])
					{


						i++;
						if(i==user_limit)
						{
							EEPROM_Write_Block_To_Address(numUsers ,arr_deleted, 4);
							EEPROM_Write_Block_To_Address(numPass, arr_deleted, 4);
							erase++;
							EEPROM_Write_Byte_To_Address(90, erase);
							uint8 x=EEPROM_Read_Byte_From_Address(85);
							x--;
							EEPROM_Write_Byte_To_Address(85, x);




							return ;


						}

					}

				}
			}
			numUsers+=4;
			numPass+=4;
}
		LCD_Init();
		LCD_WriteString("error");

		return ;


}


uint8 check_exist(uint8 name[],uint8 pass[])
{
	 uint16 numUsers=0;
	 uint16 numPass=41;

	for(;numUsers<41;)
	{
		uint8 arr[user_limit];
		uint8 arr_pass[pass_limit];
		EEPROM_Read_Block_From_Address(numUsers,arr , user_limit);
		EEPROM_Read_Block_From_Address(numPass,arr_pass , pass_limit);
		if(arr[0]==name[0])
		{
			for(int i=0 ; i<user_limit ;)
			{
				if(arr[i]==name[i])
				{

					i++;
					if(i==user_limit)
					{
						return 0;
					}

				}
				else
				{
					return 1;
				}

			}
		}
		numUsers+=4;
		numPass+=4;
	}
	return 1;


}

void add_admin()
{


	    LCD_Init();
	    LCD_WriteString("add admin");
	    _delay_ms(200);
	    LCD_Init();

		uint8 name1[user_limit];
		uint8 pass[pass_limit];

		static uint16 adminUsers=200;
		static uint16 adminPass=205;




		LCD_WriteString("user name: ");

		for(int i=0 ;i< user_limit ;)
		{
			uint8 letter =get_char();
			_delay_ms(200);
			if(letter!='m'){
			LCD_WriteChar(letter);
			name1[i]=letter;
			i++;
			}
		}



	    LCD_GoTo(1, 0);
	    LCD_WriteString("password: ");
	    for(int i=0 ;i<pass_limit;)
	    {
	    	uint8 letter =get_char();
	    	_delay_ms(200);
	    	if(letter!='m'){
	    	LCD_WriteChar(letter);
	    	pass[i]=letter;
	    	i++;

	       }
	    }


	        EEPROM_Write_Block_To_Address(adminUsers, name1 ,user_limit);
	    	EEPROM_Write_Block_To_Address(adminPass, pass ,pass_limit);









}

void restore()
{
	for(int i=0 ;i<82 ;i++)
	{
		EEPROM_Write_Byte_To_Address(i, '-');
	}
	uint8 o[4]={'-','-','-','-'};
	EEPROM_Write_Block_To_Address(200, o, 4);
	EEPROM_Write_Block_To_Address(205, o, 4);
	EEPROM_Write_Byte_To_Address(85, 0);
	EEPROM_Write_Byte_To_Address(90, 0);


}

uint8 get_char()
{
	 while(1)
					{
					uint8 x=UART_RxChar();

						if(KeyPad_GetChar()!='m'){
						uint8 x =KeyPad_GetChar();
						return x;
						x='m';
			            break;
						}

						else if(x!='m')
						{
						return x;
							x='m';
							break;
						}

					}
}
