//Nom: HAMRIOUI Prénom : GANA LAZARE
// TP1 Programmation Qt - L3 EEA mars 2019

#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // configuration fenetre principale
    setWindowTitle("TP1");
    setGeometry(100,100,800,400);

    // création de la scène graphique et de la vue (widget central)
    scene = new QGraphicsScene;

    vue= new QGraphicsView(scene);
    setCentralWidget(vue);

    // propriétés d'affichage de la vue
    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->setRenderHints(QPainter::Antialiasing| QPainter::TextAntialiasing |QPainter::SmoothPixmapTransform);

    // chargement de l'image initiale et ajustement de la tailles
    monImage=new ImageClasse(QPixmap("Campus_UHA_1.jpg"));

    scene->addItem(monImage);
    adjustSize();
    connect(scene,&QGraphicsScene::changed,this,&MainWindow::ajusteTailleVue);

    // création du titre
    zoneTitre1=new TitreClasse;

    scene->addItem(zoneTitre1);

    DemoConfigurationInitiale();

}

void MainWindow:: DemoConfigurationInitiale()
{
    //Titre
    zoneTitre1->setPlainText("  Titreuse photo - TP Licence EEA  -  Qt     ");
    zoneTitre1->setFont(QFont("Arial",75,80));
    zoneTitre1->setDefaultTextColor(QColor("red"));



    // titre encadré (optionnel) - couleur et épaisseur du cadre
    zoneTitre1->setFlagContourVisible(true);
    zoneTitre1->setFlagRectangleArrondi(true);
    zoneTitre1->setTraceContour(QPen(QColor(0,155,0),6));  // couleur et épaisseur

    // fond pour le titre (optionnel) - couleur et transparence
     zoneTitre1->setFlagBackVisible(true);
     int transparenceFond = 20 ; // valeur entre 0 totalement transparent et 255 totalement opaque
     zoneTitre1->setPinceau(QBrush(QColor(250,250,240,transparenceFond)));

    // couleur du contour de l'image
     setStyleSheet("QGraphicsView{background-color:#FFFACD}");

    // rotation du titre
    QTransform matrix;
    matrix.rotate(0, Qt::YAxis);
    zoneTitre1->setTransform(matrix);

    // position du titre et option déplacable avec la souris
    zoneTitre1->setPos(27,125);
    zoneTitre1->setFlag(QGraphicsItem::ItemIsMovable);

    enregistrerImage("ImgEnregistree/TestInital.jpg");

    // remarque : pour une qualité d'image maximale prenez format png
    //            mais pas de compression donc grand fichier

    menufile = new QMenu(this);
    menufile = menuBar()->addMenu("&Fichier");
    save = menufile -> addAction("&save");
    importimage = menufile -> addAction("&importer une nouvelle Image");
    quitter = menufile -> addAction("&Quitter");

    menuedit = new QMenu(this);
    menuedit = menuBar()->addMenu("&Edit");
    annuler = menuedit->addAction("&Annuler");
    retablir = menuedit -> addAction("&Rétablir");

    menuinsertion = new QMenu(this);
    menuinsertion = menuBar()->addMenu("&Insertion");
    zonedetext = menuinsertion -> addAction("&Zone De Text");

    menuadjust = new QMenu(this);
    menuadjust = menuBar()->addMenu("&Adjust");

    menuaide = new QMenu(this);
    menuaide = menuBar()->addMenu("&?");

    QToolBar * toolbar = addToolBar("file");
    QAction * newact1 = new QAction(QIcon("Icone_format.png"),"&Police",this);
    QAction * newact2 = new QAction(QIcon("Icone_fontSelect.png"),"&New",this);
    QAction * newact3 = new QAction(QIcon("Icone_fontSize.png"),"&Fond Size",this);
    QAction * newact4 = new QAction(QIcon("Icone_nouveau.png"),"&New",this);
    QAction * newact5 = new QAction(QIcon("Icone_textColor.png"),"&Color",this);

    newact1->setToolTip("Choix du format");
    newact2->setToolTip("Choix du font select");
    newact3->setToolTip("Choix du font size");
    newact4->setToolTip("Nouveau");
    newact5->setToolTip("Choix couleur du texte");

    toolbar->addAction(newact1);
    toolbar->addAction(newact2);
    toolbar->addAction(newact3);
    toolbar->addAction(newact4);
    toolbar->addAction(newact5);


 QObject::connect(newact3,QAction::triggered,this,&MainWindow::changepolice);
 QObject::connect(newact5,QAction::triggered,this,&MainWindow::changecolor);
 QObject::connect(save,QAction::triggered,this,&MainWindow::enregistrertravail);
 //QObject::connect(importerimage,QAction::triggered,this,&MainWindow::importerimage);


}


void MainWindow::enregistrertravail(){
    // Ouverture d'une boîte de dialogue où l'utilisateur va indiquer l'emplacement, et le nom, d'un fichier à enregistrer. La variable de type QString va contenir l'emplacement...
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Fichier Texte(*.png *.jpg )");

    // On se sert de QFile avec le chemin que l'on vient de récupérer
        QFile file(fichier);

    // Ouverture en écriture seule et petites optimisations avec QIODevice::Text
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

}
//void MainWindow::importerimage(){}
void MainWindow::enregistrerImage(QString fileName)  // enregistre le résultat dans un fichier image
{
    // supprimer marges d'affichage
    int savedMarge=monImage->margin();
 monImage->setMargin(0);

    // destination et painter
    QImage image(monImage->pixmap().size(),QImage::Format_RGB32);
    QPainter painter(&image);
    painter.setRenderHints(QPainter::Antialiasing| QPainter::TextAntialiasing |QPainter::SmoothPixmapTransform);



    // copie
    QRectF zoneCopie;
    zoneCopie.setTopLeft(QPointF(monImage->margin(),monImage->margin()));
    zoneCopie.setSize(monImage->pixmap().size());
    zoneCopie=monImage->mapRectToScene(zoneCopie);


    scene->render(&painter,QRect(QPoint(0,0),monImage->pixmap().size()),zoneCopie.toRect());

    // nom du fichier à créer
    if (!fileName.isNull())
        image.save(fileName,nullptr,90);

    // restauration des marges d'affichage
    monImage->setMargin(savedMarge);
}
//void MainWindow::dessiner(){}
void MainWindow::editdialogue(){
    QDialog * monedit = new QDialog(this);
    monedit->show();
    monedit->resize(200,400);

}
void MainWindow::changepolice(){
    bool ok = false;



        QFont police = QFontDialog::getFont(&ok,zoneTitre1->font(), this, "Choisissez une police");
        if (ok)
        {
            zoneTitre1->setFont(police);

        }
}
void MainWindow::changecolor(){


        QColor couleur=  QColorDialog::getColor(Qt::white, this);
        zoneTitre1->setTraceContour(couleur);
       QPalette palette;

           palette.setColor(QPalette::ButtonText, couleur);

           this->setPalette(palette);
}


