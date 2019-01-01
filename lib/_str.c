//
// Created by moss on 1/1/19.
//

#include "_str.h"

extern Status _str_assign(pstr t, char *s){

    if(!s){
        t->ch = NULL;
        t->length = 0;
        return 0;
    }// if NULL 处理

    pstr pt = (pstr)malloc(sizeof(str));
    if(!pt)
        exit(OVERFLOW);

    int length = 0;

    char * p = s;

    while(*p){
        ++length;
        ++p;
    }// while 计算 s 长度

    pt->ch = (char*)malloc(sizeof(char) * length);
    if(!pt->ch)
        exit(OVERFLOW);

    pt->length = length;// 将 length 赋值给 pt->length

    p = s;
    while(--length >= 0){
        (pt->ch)[length] = p[length];
    }// 将 s 赋值给 pt->ch

    *t = *pt;// 将 pt 赋值给 p

    free(pt);// 释放 pt

    return OK;

}
extern int _str_length(str s){
    return s.length;
}

extern int _str_compare(str s1, str s2){
    if(s1.length!=s2.length)
        return s1.length-s2.length;
    else
        for(int i = 0 ; i<s1.length ; i++)
            if(s1.ch[i]-s2.ch[i])
                return s1.ch[i]-s2.ch[i];
    return 0;
}

extern Status _str_concat(pstr t, str s1, str s2){
    pstr pt = (pstr)malloc(sizeof(str));
    pt->length = s1.length+s2.length;
    pt->ch = (char*)malloc(sizeof(char)*(pt->length));
    for(int i = 0;i < s1.length;i++){
        (pt->ch)[i] = (s1.ch)[i];
    }
    for(int i = s1.length;i < s2.length+s1.length;i++){
        (pt->ch)[i] = (s2.ch)[i-s1.length];
    }
    *t = *pt;
    free(pt);
}
