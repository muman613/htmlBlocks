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
    htmlBlockText*      pNewText = nullptr;

    pNewText = new htmlBlockText( sContent );

    return pNewText;
}

htmlBlockP* htmlBlockFactory::P(STRING_T sContent,
                                STRING_T sId,
                                STRING_T sClass,
                                STRING_T sStyle)
{
    htmlBlockP*         pNewP       = nullptr;
//    htmlBlockText*      pNewText    = nullptr;

    pNewP = new htmlBlockP( sId, sClass, sStyle );
    assert( pNewP != nullptr );

    if (pNewP)
        pNewP->AddText( sContent );

    return pNewP;
}

htmlBlockP* htmlBlockFactory::P(STRING_T sContent,
                                tagAttributes& attr)
{
    htmlBlockP*         pNewP       = nullptr;

    pNewP = new htmlBlockP( attr.m_sId, attr.m_sClass, attr.m_sStyle );
    assert( pNewP != nullptr );
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
    htmlBlockP*         pNewP       = nullptr;

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
    htmlBlockH1*         pNewH1       = nullptr;

    pNewH1 = new htmlBlockH1( sId, sClass, sStyle );
    pNewH1->AddText( sContent );

    return pNewH1;
}

htmlBlockH2* htmlBlockFactory::H2(STRING_T sContent,
                                  STRING_T sId,
                                  STRING_T sClass,
                                  STRING_T sStyle)
{
    htmlBlockH2*         pNewH2       = nullptr;

    pNewH2 = new htmlBlockH2( sId, sClass, sStyle );
    pNewH2->AddText( sContent );

    return pNewH2;
}
