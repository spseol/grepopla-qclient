function initObject(info) {
    var component = Qt.createComponent("../components/qml/game_components/" + info.entity + ".qml")
    var object = component.createObject(root);

    //common datas
    object.ID = info.id; //ID
    object.owner = game.playerContainer[info.values.owner_id];

    if(info.entity == "Planet") { //init specific planets properties
        //object.size = info.values.size;    //not ready
        object.x = info.values.x;
        object.y = info.values.y;
    }

    else if(info.entity == "Ship") { //init specific ships properties
        var types = ["SmallShip", "ColonisingShip"];
        object.type = types(info.values.type);
    }

    game.playerContainer[info.values.owner_id].objectContainer[info.entity][info.id] = object;
}

function initPlayer(info) {
    var component = Qt.createComponent("../components/qml/game_components/" + info.entity + ".qml")
    var object = component.createObject(root);

    object.ID = info.id

    game.playerContainer[info.id] = object;
}

function capturePlanet(info) {
    var targetPlanet = game.playerContainer[info.values.previous_owner_id].objectContainer[info.entity][info.id];

    game.playerContainer[info.values.previous_owner_id].objectContainer[info.entity].splice(info.id, 1);  //remove from list of previous owner
    game.playerContainer[info.values.capturer_id].objectContainer[info.entity][info.id] = targetPlanet;    //add planet to the new owner
}
