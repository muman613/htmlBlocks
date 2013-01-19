#ifndef HTMLBLOCKBASE_H
#define HTMLBLOCKBASE_H

#include "htmlblock_types.h"

class htmlBlockBase;
class htmlBlockText;

typedef std::vector<htmlBlockBase*>             CHILD_VECTOR;
typedef std::vector<htmlBlockBase*>::iterator   CHILD_VECTOR_ITER;

extern STRING_T emptyString;


class tagAttributes {
public:
    STRING_T            m_sId;
    STRING_T            m_sClass;
    STRING_T            m_sStyle;

    tagAttributes& operator =(const tagAttributes& copy) {
        m_sId = copy.m_sId;
        m_sClass = copy.m_sClass;
        m_sStyle = copy.m_sStyle;
        return *this;
    }
};

class htmlBlockBase
{
    public:
        htmlBlockBase()             {};
        virtual ~htmlBlockBase()    {};

        virtual STRING_T    HTML() = 0;
        virtual STRING_T    Type() = 0;
};

/**
 *
 */

class htmlBlockTagBase : public htmlBlockBase
{
    public:
        htmlBlockTagBase(STRING_T sTag,
                      STRING_T sId    = emptyString,
                      STRING_T sClass = emptyString,
                      STRING_T sStyle = emptyString);
        htmlBlockTagBase(STRING_T sTag, tagAttributes& attr);

        virtual ~htmlBlockTagBase();


        STRING_T    HTML();
        STRING_T    Type();

        virtual void        AddChild(htmlBlockBase* pNewBlock);
        void                AddText(STRING_T sText);
        void                AddCRLF();

    protected:
    private:

        STRING_T            m_sTag;
        tagAttributes       m_attr;
        CHILD_VECTOR        m_vChildren;
};

/**
 *
 */

class htmlBlockText : public htmlBlockBase
{
    public:
        htmlBlockText(STRING_T sContent);
        virtual ~htmlBlockText();

        STRING_T    HTML();
        STRING_T    Type();

private:
        STRING_T    m_sContent;
};


class htmlBlockP : public htmlBlockTagBase {
    public:
        htmlBlockP(STRING_T sId     = emptyString,
                   STRING_T sClass  = emptyString,
                   STRING_T sStyle  = emptyString);
        virtual ~htmlBlockP();
};

class htmlBlockH1 : public htmlBlockTagBase {
    public:
        htmlBlockH1(STRING_T sId     = emptyString,
                    STRING_T sClass  = emptyString,
                    STRING_T sStyle  = emptyString);
        virtual ~htmlBlockH1();
};


#endif // HTMLBLOCKBASE_H
