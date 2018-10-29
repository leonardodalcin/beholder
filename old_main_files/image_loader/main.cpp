// local packages
#include "imageloader.hpp"
// libraries
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(image_loader::tr("Beholder loader"));
    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument(image_loader::tr("[file]"), image_loader::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
    image_loader _image_loader;
    if (!commandLineParser.positionalArguments().isEmpty() && !_image_loader.loadFile(commandLineParser.positionalArguments().front())) {
	return -1;
    }
    _image_loader.show();
    return app.exec();
}
