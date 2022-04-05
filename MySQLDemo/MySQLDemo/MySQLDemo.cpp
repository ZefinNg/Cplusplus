// MySQLDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string user = "root";
	string passwd = "root";
	string host = "localhost";
	string dbName = "threekingdoms";
	unsigned int port = 3306;
	MYSQL_RES* result = NULL;

	MYSQL mysql;
	mysql_init(&mysql);

	if (mysql_real_connect(&mysql, host.data(), user.data(), passwd.data(), dbName.data(), port, NULL, 0)) {
		cout << "Connect successed." << endl;

		//设置编码格式，否则在cmd界面下会显示乱码
		mysql_query(&mysql, "SET NAMES GBK");

		//执行一个SQL查询，不需为SQL语句添加';'结尾
		int queryRet = mysql_query(&mysql, "SELECT * FROM tb_shuguo");

		if (queryRet == 0) {
			//将查询的全部结果读取到客户端，分配1个MYSQL_RES结构，并将结果置于该结构中。
			result = mysql_store_result(&mysql);
			if (result != NULL) {
				unsigned int tableCols, tableRows;
				//返回结果集中的列数
				tableCols = mysql_num_fields(result);
				//返回结果集中的行数
				tableRows = mysql_num_rows(result);

				//返回采用MYSQL_FIELD结构的结果集的列。
				MYSQL_FIELD* fields = mysql_fetch_field(result);
				
				for (int i = 0; i < tableCols; i++)
					cout << fields[i].name << "\t";

				cout << endl;

				MYSQL_ROW sqlRow;
				//检索结果集的下一行。如果没有要检索的行，mysql_fetch_row()返回NULL
				while (sqlRow = mysql_fetch_row(result)) {
					for (int i = 0; i < tableCols; i++)
						cout << sqlRow[i] << "\t";

					cout << endl;
				}
			}
		}
		else
			cout << "query sql failed." << endl;
	}
	else
		cout << "Connect failed." << endl;

	if (result != NULL) {
		//释放由mysql_store_result()、mysql_use_result()、mysql_list_dbs()等为结果集分配的内存
		mysql_free_result(result);
	}

	//关闭前面打开的连接
	mysql_close(&mysql);

    return 0;
}

