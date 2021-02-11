//Nom: HAMRIOUI Prénom : GANA LAZARE
// TP1 Programmation Qt - L3 EEA mars 2019

#ifndef IMAGECLASSE_H
#define IMAGECLASSE_H

#include <QRectF>
#include <QGraphicsPixmapItem>

// Classe pixmapItem dérivée pour créer et gérer des marges autour de l'image

class ImageClasse : public QGraphicsPixmapItem
{
    int _margin = 10;       // marge d'affichage autour de l'image

public:

    ImageClasse(QGraphicsItem *parent = Q_NULLPTR);
    ImageClasse(const QPixmap &pixmap, QGraphicsItem *parent = Q_NULLPTR);

    // pour gestion interne des contours
    virtual QRectF boundingRect() const override;

    // méthodes à utiliser pour définir l'affichage
    // - - - - - - - - - - - - - - - - - - - - - - - -
    void changerPhoto(QString nomPhoto);
    void setMargin(int m);
    int margin();
};

#endif // IMAGECLASSE_H
