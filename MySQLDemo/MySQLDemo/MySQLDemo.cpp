// MySQLDemo.cpp : �������̨Ӧ�ó������ڵ㡣
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

		//���ñ����ʽ��������cmd�����»���ʾ����
		mysql_query(&mysql, "SET NAMES GBK");

		//ִ��һ��SQL��ѯ������ΪSQL������';'��β
		int queryRet = mysql_query(&mysql, "SELECT * FROM tb_shuguo");

		if (queryRet == 0) {
			//����ѯ��ȫ�������ȡ���ͻ��ˣ�����1��MYSQL_RES�ṹ������������ڸýṹ�С�
			result = mysql_store_result(&mysql);
			if (result != NULL) {
				unsigned int tableCols, tableRows;
				//���ؽ�����е�����
				tableCols = mysql_num_fields(result);
				//���ؽ�����е�����
				tableRows = mysql_num_rows(result);

				//���ز���MYSQL_FIELD�ṹ�Ľ�������С�
				MYSQL_FIELD* fields = mysql_fetch_field(result);
				
				for (int i = 0; i < tableCols; i++)
					cout << fields[i].name << "\t";

				cout << endl;

				MYSQL_ROW sqlRow;
				//�������������һ�С����û��Ҫ�������У�mysql_fetch_row()����NULL
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
		//�ͷ���mysql_store_result()��mysql_use_result()��mysql_list_dbs()��Ϊ�����������ڴ�
		mysql_free_result(result);
	}

	//�ر�ǰ��򿪵�����
	mysql_close(&mysql);

    return 0;
}

