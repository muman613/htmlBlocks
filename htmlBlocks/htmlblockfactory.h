#ifndef HTMLBLOCKFACTORY_H
#define HTMLBLOCKFACTORY_H

#include "htmlblock_types.h"
#include "htmlblockbase.h"

class htmlBlockFactory
{
    public:
        htmlBlockFactory();
        virtual ~htmlBlockFactory();

        static htmlBlockText*           Text(STRING_T sContent);
        static htmlBlockP*              P(STRING_T sContent,
                                          STRING_T sId    = emptyString,
                                          STRING_T sClass = emptyString,
                                          STRING_T sStyle = emptyString);
        static htmlBlockP*              P(STRING_T sContent,
                                          tagAttributes& attr);
        static htmlBlockP*              P(htmlBlockBase* pContent,
                                          STRING_T sId    = emptyString,
                                          STRING_T sClass = emptyString,
                                          STRING_T sStyle = emptyString);
        static htmlBlockH1*             H1(STRING_T sContent,
                                           STRING_T sId    = emptyString,
                                           STRING_T sClass = emptyString,
                                           STRING_T sStyle = emptyString);
    protected:
    private:
};

#endif // HTMLBLOCKFACTORY_H
