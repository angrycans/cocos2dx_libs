#include <stdio.h>
#include "sqlite3.h"
#include "string.h"

#define dbPassWord "I am is a Password"
#define dbFile "data.db"

int main()
{
    sqlite3 *db;
    char pwd[100] = dbPassWord;

    if (sqlite3_open(dbFile , &db) == SQLITE_OK
            && (sqlite3_exec(db, "create table users(uid INTEGER,uname text)", NULL, NULL, NULL)==SQLITE_OK) )
    {
        printf("1.打开未加密数据库成功,正在加密……\n");
        sqlite3_rekey(db,pwd,strlen(pwd));
        sqlite3_close(db);
    }
    else{
        printf("打开未加密数据库失败\n");
        return 0;
    }

    if (sqlite3_open(dbFile , &db) == SQLITE_OK)
    {
        if(sqlite3_key(db,pwd,strlen(pwd)) == SQLITE_OK
            )
        {
            printf("2.验证加密，加密成功\n");
        }
        else{
            printf("加密失败\n");
        }
    }
/*
    if(sqlite3_rekey(db,NULL,0) == SQLITE_OK)
    {
        printf("3.解密数据库成功……\n");
        sqlite3_close(db);
    }
    */

    return 0;
}
