#ifndef APP_LOGIN_H_
#define APP_LOGIN_H_
#include "../STD_TYPES.h"
#include "../HALL/LCD.h"
#include <util/delay.h>

#define user_limit 4
#define pass_limit 4




void add_user1();
uint8 check1();
uint8 login();
void delete_user(uint8 arr[]);
uint8 check_exist(uint8 name[],uint8 pass[]);
void add_admin();

void restore();


uint8 get_char();



#endif /* APP_LOGIN_H_ */
