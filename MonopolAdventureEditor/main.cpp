#include <QApplication>
#include <QLibraryInfo>
#include <QLocale>
#include <QTextCodec>
#include <QTranslator>

#include "MainWindow.hpp"





int main(int argc, char *argv[])
{
    /* Configuration des codec en UTF-8.	  	
     */
#if QT_VERSION < 0x050000
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
#endif
    
    
    
    /* Configuration du système de traduction.
     */
    QTranslator translator;
    translator.load("qt_" + QLocale::system().name().section('_', 0, 0),
                    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    
    
    
    /* Configuration de l'application et création de la fenêtre.
     */
    QApplication app(argc, argv);
    app.installTranslator(&translator);
    
    MainWindow window;
    window.showMaximized();
    
    
    
    /* Lancement de l'application.
     */
    return app.exec();
}

