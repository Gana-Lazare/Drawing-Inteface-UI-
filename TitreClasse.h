//Nom: HAMRIOUI Prénom : GANA LAZARE
// TP1 Programmation Qt - L3 EEA mars 2019

#ifndef TITRECLASSE_H
#define TITRECLASSE_H

#include <QtWidgets>


class TitreClasse : public QGraphicsTextItem
{
    bool _flagContourVisible;
    bool _flagBackVisible;
    bool _flagRectArrondi;
    QPen _crayonContour;
    QBrush _pinceauFond;


public:
    TitreClasse(QGraphicsItem *parent = Q_NULLPTR);
    TitreClasse(const QString &text, QGraphicsItem *parent = Q_NULLPTR);

    // fonctions redéfinies pour bon fonctionnement de la classe
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *o, QWidget *w) ;
    virtual QRectF boundingRect() const;


    // méthodes à utiliser pour définir l'affichage
    // - - - - - - - - - - - - - - - - - - - - - - - -
    //     pour modifier le crayon (tracé du contour : largeur et couleur)
    void setTraceContour(const QPen & crayon);
    QPen traceContour();
    //     modifier le pinceau (couleur du rectangle)
    void setPinceau(const QBrush & brush);
    QBrush pinceau();

    // sélection des options d'affichage
    void setFlagContourVisible(bool b);     // rectangle contour autour du titre
    bool flagContourVisible() ;
    void setFlagRectangleArrondi(bool b);   // coins arrondis
    bool flagRectangleArrondi()  ;
    void setFlagBackVisible(bool b);        // arrière plan pour le titre
    bool flagBackVisible()    ;


    // remarques : méthodes héritées que vous pouvez également utiliser
    //              voir DemoConfigurationInitiale
    /*
     * setPlaintext     // texte à afficher
     * setFont          // caractères (taille et police)
     * setDefaultTextColor
     * setTransform     // calcul de rotation, d'échelle, ...
     * setPos  ou moveBy
    */

    // autres méthodes utilisables
    //        mais pas forcément en combinaison avec les précédentes
    /*
     * show
     * hide
     * setOpacity
     * setHtml      // texte avec balises HTML
     * setRotation
     * setScale
     */
};

#endif // TITRECLASSE_H
