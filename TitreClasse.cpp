//Nom: HAMRIOUI Prénom : GANA LAZARE
// TP1 Programmation Qt - L3 EEA mars 2019

#include "TitreClasse.h"

TitreClasse::TitreClasse(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    _flagContourVisible=false;
    _flagBackVisible=false;
    _flagRectArrondi=false;
}

TitreClasse::TitreClasse(const QString &text, QGraphicsItem *parent)
    :QGraphicsTextItem(text,parent)
{
    _flagContourVisible=false;
    _flagBackVisible=false;
    _flagRectArrondi=false;
}

QRectF TitreClasse::boundingRect() const
{
    QRectF r=QGraphicsTextItem::boundingRect();
    int n=1+_crayonContour.width()/2;
    return r.marginsAdded(QMarginsF(n,n,n,n));
}

QPen TitreClasse::traceContour()
{
    return _crayonContour;
}

void TitreClasse::setTraceContour(const QPen &crayon)
{
    if (_crayonContour==crayon)
        return;
    prepareGeometryChange();
    _crayonContour=crayon;
    update();
}

void TitreClasse::setPinceau(const QBrush & brush)
{
    _pinceauFond = brush;
}

QBrush TitreClasse::pinceau()
{
    return _pinceauFond;
}


// flag de sélection des options d'affichage
bool TitreClasse::flagContourVisible()               // rectangle contour du titre
{
    return _flagContourVisible;
}
void TitreClasse::setFlagContourVisible(bool b)
{
    _flagContourVisible =b;
}

bool TitreClasse::flagRectangleArrondi()                  // si contour visible, sélection coin arrondi
{
    return _flagRectArrondi;
}
void TitreClasse::setFlagRectangleArrondi(bool b)
{
    _flagRectArrondi = b;
}

bool TitreClasse::flagBackVisible()                  // arrière plan pour le titre
{
    return _flagBackVisible;
}

void TitreClasse::setFlagBackVisible(bool b)
{
    _flagBackVisible = b;
}


void TitreClasse::paint( QPainter *painter, const QStyleOptionGraphicsItem *o, QWidget *w)
{
    // tracé du contour et arrière plan du texte
    // sélection du crayon et du pinceau en fonction des options
    if (_flagContourVisible)
    {
        painter->setPen(_crayonContour);
    }
    else
        painter->setPen(Qt::NoPen);

    if (_flagBackVisible)
    {
      //  painter->setBackgroundMode(Qt::OpaqueMode);
        painter->setBrush(_pinceauFond);
    }
    else
        painter->setBrush(Qt::NoBrush);

    painter->setRenderHint(QPainter::Antialiasing);

    if (_flagRectArrondi)
        painter->drawRoundedRect(boundingRect(),20,15);
    else
        painter->drawRect(boundingRect());

    
    // méthode de base pour affichage de l'image
    QGraphicsTextItem::paint(painter, o, w);
}




