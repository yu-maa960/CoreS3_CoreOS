#include "AppHome.h"
#include "Common/App_State.h"
#include "Common/SystemTypes.h"
#include "HAL/MyUI.h"
#include "HAL/My_WiFi.h"
#include "OS/CoreOS.h"

void AppHome::setup() {
    MyUI::drawHomeScreen();
    IPAdr = My_WiFi::getIPAdr();
    if (IPAdr != nullptr && IPAdr[0] != '\0') {
        MyUI::drawIPAddress(IPAdr);
        IPDrawn = true;
    }
}

void AppHome::loop() {
    if (!IPDrawn) {
        IPAdr = My_WiFi::getIPAdr();
        if (IPAdr != nullptr && IPAdr[0] != '\0') {
            MyUI::drawIPAddress(IPAdr);
            IPDrawn = true;
        }
    }

    Mode nextMode{MyUI::checkMenuSelection()};
    if (nextMode != Mode::HOME) {
        if (nextMode == Mode::Controller) {
            MyUI::drawController();
            delay(2000);
            MyUI::drawHomeScreen();
        } else {
            OSRequest req{};
            req.type = RequestType::APP_INITIALIZE;
            req.state = nextMode;
            CoreOS::getInstance().post(req);
        }
    }
}

void AppHome::stop() {
    
}

