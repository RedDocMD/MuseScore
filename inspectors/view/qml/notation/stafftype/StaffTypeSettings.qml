import QtQuick 2.9
import QtQuick.Layouts 1.3
import MuseScore.Inspectors 3.3
import "../../common"

PopupViewButton {
    id: root

    property alias model: staffTypePopup.model

    icon: IconNameTypes.STAFF_TYPE_CHANGE
    text: qsTr("Staff type changes")

    visible: root.model ? !root.model.isEmpty : false

    StaffTypePopup {
        id: staffTypePopup

        x: popupPositionX
        y: popupPositionY
        arrowX: parent.x + parent.width / 2
        width: popupAvailableWidth
    }
}
