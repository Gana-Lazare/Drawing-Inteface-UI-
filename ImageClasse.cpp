//Nom: HAMRIOUI Prénom : GANA LAZARE
#include "ImageClasse.h"

ImageClasse::ImageClasse(QGraphicsItem *parent )
    :QGraphicsPixmapItem(parent)
{
    _margin = 10;       // valeur par défaut
    setTransformationMode(Qt::SmoothTransformation);
}

ImageClasse::ImageClasse(const QPixmap &pixmap, QGraphicsItem *parent)
    :QGraphicsPixmapItem(pixmap,parent)
{
    _margin = 10;       // valeur par défaut
    setTransformationMode(Qt::SmoothTransformation);
}

void ImageClasse::changerPhoto(QString nomPhoto)
{
    setPixmap(QPixmap(nomPhoto));

  //  vue->fitInView(itemImage,Qt::KeepAspectRatio);
  //  adjustSize();
}

void ImageClasse::setMargin(int m)
{
    _margin=m;
}

int ImageClasse::margin()
{
    return _margin;
}

// gestion des marges
QRectF ImageClasse::boundingRect() const
{
    QRectF r=QGraphicsPixmapItem::boundingRect();
    return r.marginsAdded(QMarginsF(_margin,_margin,_margin,_margin));
}
