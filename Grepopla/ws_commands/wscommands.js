function initObject(id, entity, owner_id, x, y, size) {
    var component = Qt.createComponent("../components/qml/game_components/" + entity + ".qml")
    var object = component.createObject(root);

    //common datas
    object.ID = id; //ID
    object.x = x;
    object.y = y;
    object.owner = game.playerContainer[owner_id];

    if(entity == "Planet") { //init specific planets properties
        //object.size = size;    //not ready
    }

    else if(entity == "Ship") { //init specific ships properties
        var types = ["SmallShip", "ColonisingShip"];
        object.size = types(size);
    }

    game.playerContainer[owner_id].objectContainer[entity][id] = object;
}

function initPlayer(id, entity) {
    var component = Qt.createComponent("../components/qml/game_components/" + entity + ".qml")
    var object = component.createObject(root);

    object.ID = id

    game.playerContainer[id] = object;
}

function capturePlanet(id, entity, capturer_id, previous_owner_id) {
    var targetPlanet = game.playerContainer[previous_owner_id].objectContainer[entity][id];

    game.playerContainer[previous_owner_id].objectContainer[entity].splice(id, 1);  //remove from list of previous owner
    game.playerContainer[capturer_id].objectContainer[entity][id] = targetPlanet;    //add planet to the new owner
}
