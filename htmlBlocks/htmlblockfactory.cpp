#include <stdio.h>
#include <assert.h>
#include "htmlblockfactory.h"

htmlBlockFactory::htmlBlockFactory()
{
    //ctor
}

htmlBlockFactory::~htmlBlockFactory()
{
    //dtor
}


htmlBlockText* htmlBlockFactory::Text(STRING_T sContent)
{
    htmlBlockText*      pNewText = 0L;

    pNewText = new htmlBlockText( sContent );

    return pNewText;
}

htmlBlockP* htmlBlockFactory::P(STRING_T sContent,
                                STRING_T sId,
                                STRING_T sClass,
                                STRING_T sStyle)
{
    htmlBlockP*         pNewP       = 0L;
//    htmlBlockText*      pNewText    = 0L;

    pNewP = new htmlBlockP( sId, sClass, sStyle );
    assert( pNewP != 0L );

    if (pNewP)
        pNewP->AddText( sContent );

    return pNewP;
}

htmlBlockP* htmlBlockFactory::P(STRING_T sContent,
                                tagAttributes& attr)
{
    htmlBlockP*         pNewP       = 0L;

    pNewP = new htmlBlockP( attr.m_sId, attr.m_sClass, attr.m_sStyle );
    assert( pNewP != 0L );
    if (pNewP) {
        pNewP->AddText( sContent );
    }

    return pNewP;
}

htmlBlockP* htmlBlockFactory::P(htmlBlockBase* pContent,
                                STRING_T sId,
                                STRING_T sClass,
                                STRING_T sStyle)
{
    htmlBlockP*         pNewP       = 0L;

    pNewP = new htmlBlockP( sId, sClass, sStyle );

    if (pNewP) {
        pNewP->AddChild( pContent );
    }

    return pNewP;
}

/**
        static htmlBlockP*              P(htmlBlockBase* pContent,
                                          STRING_T sId    = emptyString,
                                          STRING_T sClass = emptyString,
                                          STRING_T sStyle = emptyString);
*/

htmlBlockH1* htmlBlockFactory::H1(STRING_T sContent,
                                STRING_T sId,
                                STRING_T sClass,
                                STRING_T sStyle)
{
    htmlBlockH1*         pNewH1       = 0L;
//    htmlBlockText*      pNewText    = 0L;

    pNewH1 = new htmlBlockH1( sId, sClass, sStyle );
    assert( pNewH1 != 0L );

    if (pNewH1)
        pNewH1->AddText( sContent );

    return pNewH1;
}
