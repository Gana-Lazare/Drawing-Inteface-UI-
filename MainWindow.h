//Nom: HAMRIOUI Prénom : GANA LAZARE
// TP1 Programmation Qt - L3 EEA mars 2019

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "TitreClasse.h"
#include "ImageClasse.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene * scene;
    QGraphicsView * vue;
    ImageClasse * monImage;
    TitreClasse * zoneTitre1;
    QLabel * droite;
    QLabel * gauche;
    QMenu * menufile;
    QMenu * menuedit;
    QMenu * menuinsertion;
    QMenu * menuadjust;
    QMenu * menuaide;
    QAction * save;
    QAction * importimage;
    QAction * quitter;
    QAction * annuler;
    QAction * retablir;
    QAction * zonedetext;
    QLineEdit * changetitre;
    QPainter * rectangle;

public:
    MainWindow(QWidget *parent = 0);

    void DemoConfigurationInitiale();

public slots:
    void ajusteTailleVue()
    {
       // ajustement de la vue à la taille de l'image
       vue->fitInView(monImage->boundingRect(),Qt::KeepAspectRatio);
    }

    void enregistrerImage(QString fileName);
    void enregistrertravail();

    void editdialogue();
    void changepolice();
    void changecolor();



protected:
    // fonction redéfinie pour ajustement automatique de la taille de l'image
    virtual void resizeEvent(QResizeEvent *) override
    {
        ajusteTailleVue();
    }
};

#endif // MAINWINDOW_H
