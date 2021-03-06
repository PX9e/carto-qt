#include "data_categories.h"


bool initCategoriesTable(){
    QSqlQuery query(database::dataCreate()->dataConnect());

    if(query.exec("create table categories ("
                  "categorie_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "categorie VARCHAR(64),"
                  "unique (categorie))") == false)
    {
        qDebug()<< "initCategoriesTable" << query.lastError().text();
        return false;
    }
    return true;
}

bool addCategorie(QString categorie){
    QSqlQuery query(database::dataCreate()->dataConnect());
    if( query.exec("insert into categories(categorie) values('"
                   + categorie
                   + "')") == false)
    {
        qDebug()<< "addCategorie" << query.lastError().text();
        return false;
    }
    return true;
}

QString getCategorieById(int id){
    QSqlQuery query(database::dataCreate()->dataConnect());

     if(query.exec("SELECT categorie FROM categories WHERE categorie_id = '"+ QString::number(id) +"'") == false)
     {
         qDebug()<< "getCategorieById" << query.lastError().text();
         exit(1);
     }

     query.next();

     return query.value(0).toString();
}

int getCategorieIdByName(QString name){
    QSqlQuery query(database::dataCreate()->dataConnect());

     if(query.exec("SELECT categorie_id FROM categories WHERE categorie = '"+ name +"'") == false)
     {
         qDebug()<< "getCategorieByPoint" << query.lastError().text();
         exit(1);
     }

     query.next();
     return query.value(0).toInt();
}
