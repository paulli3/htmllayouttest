#include "sqlite3.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#ifdef DEBUG
    void debug(char * str){
        std::cout << str <<"\n";
    }
    void debug(std::map<std::string,std::string> Map)
    {
        std::cout << "debug --------------------> \n";
        for(auto iter1 = Map.begin(); iter1 != Map.end(); ++iter1) 
        {
            std::cout << iter1->first << "=" << iter1->second << "\n";
        }  
    }
#else
    void debug(char * str){};
    void debug(std::map<std::string,std::string> Map){};

#endif    

//cl sql.cpp /I ../include ../lib/SQLITE3.lib /Fe:"../sql.exe" /EHsc
class Result
{
    public :
        std::vector<std::map<std::string,std::string>> fields;
        std::map<std::string,std::string> Field;
        int i=0;
        bool setField(char* filedName, char* value)
        {
           Field[std::string(filedName)] = std::string(value);
           return true;
        }
        bool addRow()
        {
            fields.push_back(Field);
            Field.clear();
            return true;
        }
        std::map<std::string,std::string> getone()
        {
            return fields[i++];
        }
};
class sql
{
    private:
        char * errmsg;
    public :
        std::string dbFile;
        sqlite3 *db;
        Result  mResult ;


        sql(std::string filePath)
        {
            dbFile=filePath;
            connect();
            Result mResult;
        }
        bool connect();
        bool query(std::string sql,sqlite3_callback Xcallback )
        {
            int ret;
            ret = sqlite3_exec(db,sql.c_str(),Xcallback,static_cast<void*>(&mResult),&errmsg);
            if (! ret == SQLITE_OK){
                char d[255];
                sprintf(d,"query fail! [%s] [%s]",sql.c_str(),sqlite3_errmsg(db));
                debug(d);
                return false;
            }
            return true;
        }
        int static callback(void*p_data ,int nCount,char** pValue,char** pName)
        {
            Result * pResult = reinterpret_cast<Result*>(p_data);
            for(int i=0; i< nCount; ++i)
            {
                pResult->setField(pName[i],pValue[i]);
                // std::cout << pName[i] << "=" << pValue[i] << "\n";
            }
            pResult->addRow();
            return 0;
        }

        bool findone(std::string sql);
        
        inline bool createTable()
        {
            std::string sql;
            sql = "create table if not exists main(id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT , content TEXT , create_time INTEGER  )";
            return  query(sql,NULL);
        }
        
};
bool sql::connect()
{
    int ret;
    ret = sqlite3_open(dbFile.c_str(),&db);
    if( ret ){   
        fprintf(stderr,"Can't open database: %s/n", sqlite3_errmsg(db));
        sqlite3_close(db);   
        return false;   
    }      
    debug("connect success;");
    return true;
}


int main()
{
    sql db("D:/t");
    db.createTable();
    db.query("insert into main values(NULL,'22222222222','xxxxx',11111);",NULL);
    db.query("select * from main;",db.callback);
    //while (db.mResult.getone()){
    
    debug(db.mResult.getone());
    //}
    std::map<std::string ,std::string> testmap;
    testmap["aaaa"] = "bbbbb";
    std::cout << testmap["aaaa"];
}
