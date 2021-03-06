function initObject(id, entity, owner_id, x, y, size) {
    var component = Qt.createComponent("../components/qml/game_components/" + entity + ".qml")
    var object = component.createObject(root);

    //common datas
    object.ID = id; //ID
    object.x = x;
    object.y = y;
    object.owner = game.playerContainer[owner_id];

    if(entity == "Planet") { //init specific planets properties
        object.width = size * 100;
        object.height = size * 100;//object.size = size;    //not ready
    }

    else if(entity == "Ship") { //init specific ships properties
        var types = ["SmallShip", "ColonisingShip"];
        object.type = size-1;
        //console.log(x +"/"+y)
        object.width = 75;
        object.height = 75;

        //test code
        //if(owner_id == game.myID)
          //  console.log(id)
    }

    game.playerContainer[owner_id].objectContainer[entity][id] = object;
}

function requestInit() {
    var datas = {}
    datas.command = "request"
    datas.entity = "Ship"

    socket.sendTextMessage(JSON.stringify(datas))
}

function initPlayer(id, entity, nick) {
    if(game.myNick == nick)
        game.myID = id
    var component = Qt.createComponent("../components/qml/game_components/" + entity + ".qml")
    var object = component.createObject(root);

    object.ID = id
    object.nick = nick

    game.playerContainer[id] = object;
}

function capturePlanet(id, entity, capturer_id, previous_owner_id) {
    var targetPlanet = game.playerContainer[previous_owner_id].objectContainer[entity][id];

    game.playerContainer[previous_owner_id].objectContainer[entity].splice(id, 1);  //remove from list of previous owner
    game.playerContainer[capturer_id].objectContainer[entity][id] = targetPlanet;    //add planet to the new owner
}

function followShip(id, owner_id, following_ship_id, follower_id) {
    game.playerContainer[owner_id].objectContainer["Ship"][id].startEmitDestination(game.playerContainer[follower_id].objectContainer["Ship"][following_ship_id]);
}

function unfollowShip(id, owner_id) {
    game.playerContainer[owner_id].objectContainer["Ship"][id].unfollow();
}

function move(id, owner_id, x, y) {
    //game.playerContainer[owner_id].objectContainer["Ship"][id].focus = true
    game.playerContainer[owner_id].objectContainer["Ship"][id].updateDestination = true;
    game.playerContainer[owner_id].objectContainer["Ship"][id].destination = Qt.point(x, y);
}
