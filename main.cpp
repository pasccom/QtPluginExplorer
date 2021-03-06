/* Copyright 2015-2020 Pascal COMBES <pascom@orange.fr>
 *
 * This file is part of QtPluginExplorer.
 *
 * QtPluginExplorer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QtPluginExplorer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QtPluginExplorer. If not, see <http://www.gnu.org/licenses/>
 */

#include <QFileInfo>
#include <QPluginLoader>
#include <QJsonDocument>

#include <iostream>

void displayHelp(const char* progName)
{
    std::cout << "Usage: " << progName << " [-h|--help|-v|--version] plugin" << std::endl;
    std::cout << std::endl;
    std::cout << "Explore Qt plugins." << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "\t-h or --help: Display this help" << std::endl;
    std::cout << "\t-v or --version: Display version" << std::endl;
    std::cout << std::endl;
    std::cout << "Arguments:" << std::endl;
    std::cout << "\tplugin: Path the the plugin file." << std::endl;
    exit(0);
}

void displayVersion()
{
    std::cout << "QtPluginExplorer version 0.0.1" << std::endl;
    exit(0);
}

int main(int argc, char *argv[])
{
    if ((argc != 2) || (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))
        displayHelp(argv[0]);

    if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0))
        displayVersion();

    if (!QFileInfo::exists(argv[1])) {
        std::cout << qPrintable(QString("Given file path \"%1\" does not exist.").arg(argv[1])) << std::endl;
        return 1;
    }

    QPluginLoader loader;
    loader.setFileName(QFileInfo(argv[1]).absoluteFilePath());
    QJsonDocument metaData = QJsonDocument(loader.metaData());
    std::cout << metaData.toJson().constData();


    return 0;
}
