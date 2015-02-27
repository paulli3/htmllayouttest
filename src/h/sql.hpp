#include "sqlite3.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "window.h"
#ifndef DEBUG
    /* void DDebug(const char * str){  */
        // std::cout << str <<"\n";
    // }
    // void DDebug(std::map<std::string,std::string> Map)
    // {
        // std::cout << "debug --------------------> \n";
        // for(auto iter1 = Map.begin(); iter1 != Map.end(); ++iter1) 
        // {
            // std::cout << iter1->first << "=" << iter1->second << "\n";
        // }  
    /* }  */
#else
   /*  void Debug(const char * str){ */
    
    // }; 
    // void Debug(std::map<std::string,std::string> Map){
    
   /*  } */; 

#endif    

#ifndef SQL_CLASS
#define SQL_CLASS 1
//cl sql.cpp /I ../include ../lib/SQLITE3.lib /Fe:"../sql.exe" /EHsc
class Record
{
    public :
        std::map<std::string,std::string> field;
        void add(const char* fileName,const char * value)
        {
            field[fileName] = value;
        }
        void clear()
        {
            field.clear();
        }
        std::string get(std::string fieldName)
        {
            return field[fieldName];
        }

};
class Result
{
    public :
        std::vector<Record> fields;
        Record Field;
        int i=0;
        bool setField(char* filedName, char* value)
        {
            // Field[std::string(filedName)] = std::string(value);
            Field.add(filedName,value);
           return true;
        }
        bool addRow()
        {
            fields.push_back(Field);
            Field.clear();
            return true;
        }
        Record* getone() 
        {
            if (i < fields.size()){
                return &fields[i++];
            }else{
                return 0;
            }
        } 
        void reset()
        {
            i=0;
            Field.clear();
            fields.clear();
        }
};
class sql
{
    private:
        char * errmsg;
        Result  mResult ;
    public :
        sqlite3 *db;


        sql(std::string filePath)
        {
            //MessageBox(NULL,filePath.c_str(),"1",0);
            connect(filePath);
        }
        sql(){}
        bool connect(std::string dbFile)
        {
            int ret;
            ret = sqlite3_open(dbFile.c_str(),&db);
            if( ret ){   
                fprintf(stderr,"Can't open database: %s/n", sqlite3_errmsg(db));
                sqlite3_close(db);
                MessageBox(NULL,"connect db error","error",MB_OK);
                return false;   
            }      

            //DDebug("connect success;");
            return true;
        }

        Result * RESCULT() 
        {
            return &mResult;
        }
        bool query(std::string sql/* ,sqlite3_callback Xcallback  */)
        {
            //mResult.reset();
            int ret;
            ret = sqlite3_exec(db,sql.c_str(),&callback,static_cast<void*>(&mResult),&errmsg);
            if (! ret == SQLITE_OK){
                char d[255];
                sprintf(d,"query fail! [%s] [%s]",sql.c_str(),sqlite3_errmsg(db));
                //Debug(d);
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
            return  query(sql);
        }
        
};
sql * PSQL = new sql();
#endif

/* int main() */
// {
    // sql db("D:/t");
    // db.createTable();
    // db.query("insert into main values(NULL,'22222222222','xxxxx',11111);");
    // db.query("select * from main;");

    // Record * precode;
    // while ( (precode = db.RESCULT()->getone() )){
     // debug(precode->get("id").c_str());
    // }
    // db.query("select * from main;");

    // while ( (precode = db.RESCULT()->getone() )){
     // debug(precode->get("id").c_str());
    // }
/* } */
