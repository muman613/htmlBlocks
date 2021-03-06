#include <cassert>
#include "htmlblockbase.h"


STRING_T        emptyString;

htmlBlockTagBase::htmlBlockTagBase(STRING_T sTag, STRING_T sId, STRING_T sClass,
                                   STRING_T sStyle)
:   m_bAddCr(false),
    m_sTag(sTag)
{
    //ctor
    m_attr.m_sId    = sId;
    m_attr.m_sClass = sClass;
    m_attr.m_sStyle = sStyle;
}

htmlBlockTagBase::htmlBlockTagBase(STRING_T sTag, tagAttributes& attr)
:   m_sTag(sTag)
{
    //ctor
    m_attr = attr;
}

htmlBlockTagBase::~htmlBlockTagBase()
{
    CHILD_VECTOR_ITER   cIter;
    for (cIter = m_vChildren.begin() ; cIter != m_vChildren.end() ; cIter++) {
        delete (*cIter);
    }
}

STRING_T htmlBlockTagBase::HTML() {
    CHILD_VECTOR_ITER   cIter;
    STRING_T            sHTML;

    sHTML += "<" + m_sTag;
    if (!m_attr.m_sId.empty()) {
        sHTML += " id=\"" + m_attr.m_sId + "\"";
    }
    if (!m_attr.m_sClass.empty()) {
        sHTML += " class=\"" + m_attr.m_sClass + "\"";
    }
    if (!m_attr.m_sStyle.empty()) {
        sHTML += " style=\"" + m_attr.m_sStyle + "\"";
    }
    sHTML += ">";

    if (m_bAddCr)
        sHTML += "\n";

    for (cIter = m_vChildren.begin() ; cIter != m_vChildren.end() ; cIter++)
    {
        sHTML += (*cIter)->HTML();
    }

    sHTML += "</" + m_sTag + ">";

    if (m_bAddCr)
        sHTML += "\n";

    return sHTML;
}

STRING_T htmlBlockTagBase::Type() {
    STRING_T    sType = "TAG";

    return sType;
}

void htmlBlockTagBase::AddChild(htmlBlockBase* pNewBlock)
{
    m_vChildren.push_back( pNewBlock );
}

void htmlBlockTagBase::AddText(STRING_T sText)
{
    htmlBlockText*      pNewText = nullptr;

    pNewText = new htmlBlockText( sText );
    AddChild( pNewText );
}

void htmlBlockTagBase::AddCRLF() {
    AddText("\r\n");
}

/*----------------------------------------------------------------------------*/

htmlBlockText::htmlBlockText(STRING_T sContent)
:   m_sContent(sContent)
{

}

htmlBlockText::~htmlBlockText()
{

}

STRING_T htmlBlockText::Type()
{
    return "TEXT";
}

STRING_T htmlBlockText::HTML()
{
    return m_sContent;
}

/*----------------------------------------------------------------------------*/

htmlBlockP::htmlBlockP(STRING_T sId, STRING_T sClass, STRING_T sStyle)
:   htmlBlockTagBase( "P", sId, sClass, sStyle)
{

}

htmlBlockP::~htmlBlockP()
{

}

/*----------------------------------------------------------------------------*/

htmlBlockH1::htmlBlockH1(STRING_T sId, STRING_T sClass, STRING_T sStyle)
:   htmlBlockTagBase( "H1", sId, sClass, sStyle)
{

}

htmlBlockH1::~htmlBlockH1()
{

}

/*----------------------------------------------------------------------------*/

htmlBlockH2::htmlBlockH2(STRING_T sId, STRING_T sClass, STRING_T sStyle)
    :   htmlBlockTagBase( "H2", sId, sClass, sStyle)
{

}

htmlBlockH2::~htmlBlockH2()
{

}

/*----------------------------------------------------------------------------*/

htmlBlockHEAD::htmlBlockHEAD()
:   htmlBlockTagBase( "HEAD" )
{
    m_bAddCr = true;
}

htmlBlockHEAD::~htmlBlockHEAD()
{

}

void htmlBlockHEAD::AddTitle(STRING_T sTitle) {
    htmlBlockTITLE * newTitle = new htmlBlockTITLE(sTitle);

    AddChild(newTitle);
}

/*----------------------------------------------------------------------------*/

htmlBlockTITLE::htmlBlockTITLE(STRING_T sTitle)
:   htmlBlockTagBase("TITLE"),
    m_sTitle(sTitle)
{
    AddText(sTitle);
}

htmlBlockTITLE::~htmlBlockTITLE() {

}

/*----------------------------------------------------------------------------*/

htmlBlockBODY::htmlBlockBODY()
:   htmlBlockTagBase( "BODY" )
{
    m_bAddCr = true;
}

htmlBlockBODY::~htmlBlockBODY()
{

}


/*----------------------------------------------------------------------------*/

htmlBlockHTML::htmlBlockHTML()
:   htmlBlockTagBase( "HTML" ),
    m_pHead(0L),
    m_pBody(0L)
{
    m_pHead = new htmlBlockHEAD();
    AddChild( m_pHead );
    m_pBody = new htmlBlockBODY();
    AddChild( m_pBody );
    m_bAddCr = true;
}

htmlBlockHTML::~htmlBlockHTML()
{
    // dtor
}

void htmlBlockHTML::AddToHead(htmlBlockTagBase* pContent)
{
    m_pHead->AddChild( pContent );
}

void htmlBlockHTML::AddToBody(htmlBlockTagBase* pContent)
{
    m_pBody->AddChild( pContent );
}

htmlBlockHEAD*       htmlBlockHTML::Head() {
    return static_cast<htmlBlockHEAD*>(m_pHead);
}

htmlBlockBODY*       htmlBlockHTML::Body() {
    return static_cast<htmlBlockBODY*>(m_pBody);
}
