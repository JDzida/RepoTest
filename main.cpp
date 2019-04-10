#include <QCoreApplication>
#include <QNetworkInterface>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QNetworkInterface> interface = QNetworkInterface::allInterfaces();


    QList<QNetworkAddressEntry> entries = interface.at(1).addressEntries();

    QString ad = entries.at(0).ip().toString();
    std::string ips = ad.toUtf8().constData();

    std::cout << ips << std::endl; //shows my ip address

    ips.erase(std::remove(ips.begin(), ips.end(), '.'), ips.end());

    uint32_t val = std::stoi(ips);

    std::cout << val << std::endl; //shows ip without .



    return a.exec();
}
