var group__unpackers =
[
    [ "mqtt_fixed_header", "structmqtt__fixed__header.html", [
      [ "control_flags", "structmqtt__fixed__header.html#a0b2c864e38b4b39b4832cea95e9dd9b5", null ],
      [ "control_type", "structmqtt__fixed__header.html#a38137e33da64798868b8bbc24dc44d23", null ],
      [ "remaining_length", "structmqtt__fixed__header.html#aa5c106b271f831833cc61a73ab48ba04", null ]
    ] ],
    [ "mqtt_response_connack", "structmqtt__response__connack.html", [
      [ "mqtt_unpack_connack_response", "group__unpackers.html#gaa174fec8a214d65ee887b5b6c9b79d78", null ],
      [ "return_code", "structmqtt__response__connack.html#a54995c3252ea2954e0dffc8726bb7d5a", null ],
      [ "session_present_flag", "structmqtt__response__connack.html#a1583e72ac8f111a02dc358fd52aecdbf", null ]
    ] ],
    [ "mqtt_response_publish", "structmqtt__response__publish.html", [
      [ "mqtt_unpack_publish_response", "group__unpackers.html#gae8ee6c1da210c4782f4f9939fe6ec828", null ],
      [ "application_message", "structmqtt__response__publish.html#a47c981a9cc2104180894a0b6d2effdf7", null ],
      [ "application_message_size", "structmqtt__response__publish.html#a2c5827a8beae468145ad52c623d884d8", null ],
      [ "dup_flag", "structmqtt__response__publish.html#a9825dfd93788834d25c5dd67e068aadc", null ],
      [ "packet_id", "structmqtt__response__publish.html#ad051e090f3817f4549df7dc178790f45", null ],
      [ "qos_level", "structmqtt__response__publish.html#a9d819901d7d0f5139ca4d3100af5ef11", null ],
      [ "retain_flag", "structmqtt__response__publish.html#ac20258a37b5ef85548dab7c9ba743a69", null ],
      [ "topic_name", "structmqtt__response__publish.html#a0f388655527c9be685d56d0670910524", null ],
      [ "topic_name_size", "structmqtt__response__publish.html#afe1d8fdb0ec5705da6f5c3ed5aad83ab", null ]
    ] ],
    [ "mqtt_response_puback", "structmqtt__response__puback.html", [
      [ "mqtt_unpack_pubxxx_response", "group__unpackers.html#ga8c9b9bb3aab29bfca1408b9e5c5d4a01", null ],
      [ "packet_id", "structmqtt__response__puback.html#ad051e090f3817f4549df7dc178790f45", null ]
    ] ],
    [ "mqtt_response_pubrec", "structmqtt__response__pubrec.html", [
      [ "packet_id", "structmqtt__response__pubrec.html#ad051e090f3817f4549df7dc178790f45", null ]
    ] ],
    [ "mqtt_response_pubrel", "structmqtt__response__pubrel.html", [
      [ "packet_id", "structmqtt__response__pubrel.html#ad051e090f3817f4549df7dc178790f45", null ]
    ] ],
    [ "mqtt_response_pubcomp", "structmqtt__response__pubcomp.html", [
      [ "packet_id", "structmqtt__response__pubcomp.html#ad051e090f3817f4549df7dc178790f45", null ]
    ] ],
    [ "mqtt_response_suback", "structmqtt__response__suback.html", [
      [ "mqtt_unpack_suback_response", "structmqtt__response__suback.html#a52a9d997a2d4dbe6fd2abc6d458df908", null ],
      [ "num_return_codes", "structmqtt__response__suback.html#a4cae95efa09aa5958a9ddf83ef765266", null ],
      [ "packet_id", "structmqtt__response__suback.html#ad051e090f3817f4549df7dc178790f45", null ],
      [ "return_codes", "structmqtt__response__suback.html#a1a67489f18f081895a765c64a0b6f571", null ]
    ] ],
    [ "mqtt_response_unsuback", "structmqtt__response__unsuback.html", [
      [ "mqtt_unpack_unsuback_response", "structmqtt__response__unsuback.html#af47bfa86aab0876c6855edad4d1bbbc0", null ],
      [ "packet_id", "structmqtt__response__unsuback.html#ad051e090f3817f4549df7dc178790f45", null ]
    ] ],
    [ "mqtt_response_pingresp", "structmqtt__response__pingresp.html", [
      [ "dummy", "structmqtt__response__pingresp.html#a7c1d654b7b6114d7a0abc8d351dd1bcd", null ]
    ] ],
    [ "mqtt_response", "structmqtt__response.html", [
      [ "mqtt_unpack_response", "group__unpackers.html#gaae124a93579dcd31e6f52411f4582fbd", null ],
      [ "connack", "structmqtt__response.html#a7cb148abc5684c6f9f612f9e9ff1702b", null ],
      [ "decoded", "structmqtt__response.html#a372d1eb7cefce7d97f5412388280d9a3", null ],
      [ "fixed_header", "structmqtt__response.html#ae6c74d23295042d047eda8a09cf25d20", null ],
      [ "pingresp", "structmqtt__response.html#a140ce25787d7b7d9ff2a487133671759", null ],
      [ "puback", "structmqtt__response.html#a89984a0ee07f07a78c111ac12bdbdf91", null ],
      [ "pubcomp", "structmqtt__response.html#a1b8a36de3eb0cacc048f43d10e154a86", null ],
      [ "publish", "structmqtt__response.html#acd3d4d35a2e048879f9141868af039a4", null ],
      [ "pubrec", "structmqtt__response.html#adc00a0958c635933a41033b23885f588", null ],
      [ "pubrel", "structmqtt__response.html#a643f7abb9085da3ea5c2e65f28d9b9f8", null ],
      [ "suback", "structmqtt__response.html#a0178987cd279100b014f3537733b1411", null ],
      [ "unsuback", "structmqtt__response.html#a1611e6afee8179b79c3f950ec504ecd8", null ]
    ] ],
    [ "MQTTConnackReturnCode", "group__unpackers.html#ga07e480dfa5738e60c54ad0447ddb1a25", [
      [ "MQTT_CONNACK_ACCEPTED", "group__unpackers.html#gga07e480dfa5738e60c54ad0447ddb1a25a8ed62964c597ddea739324ac904e423a", null ],
      [ "MQTT_CONNACK_REFUSED_PROTOCOL_VERSION", "group__unpackers.html#gga07e480dfa5738e60c54ad0447ddb1a25a6630a3751629a3bffa7c4d10255942cc", null ],
      [ "MQTT_CONNACK_REFUSED_IDENTIFIER_REJECTED", "group__unpackers.html#gga07e480dfa5738e60c54ad0447ddb1a25a008fd8f71e743057757dcb06ddbfdaef", null ],
      [ "MQTT_CONNACK_REFUSED_SERVER_UNAVAILABLE", "group__unpackers.html#gga07e480dfa5738e60c54ad0447ddb1a25ab8f59dfc09af88dd3099932b25123e61", null ],
      [ "MQTT_CONNACK_REFUSED_BAD_USER_NAME_OR_PASSWORD", "group__unpackers.html#gga07e480dfa5738e60c54ad0447ddb1a25aa4ff9b812e7b4ba789bc55ee5e6da622", null ],
      [ "MQTT_CONNACK_REFUSED_NOT_AUTHORIZED", "group__unpackers.html#gga07e480dfa5738e60c54ad0447ddb1a25a4a231c1d42dfd20e926b3f5deafc04bf", null ]
    ] ],
    [ "MQTTControlPacketType", "group__unpackers.html#gacbd36b88ec7f62bc161b07e1a0aed679", [
      [ "MQTT_CONTROL_CONNECT", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679ac82ec571db883b701b3e062db61a9408", null ],
      [ "MQTT_CONTROL_CONNACK", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679ac4f13496814d2b529f0537b71ffe1cdf", null ],
      [ "MQTT_CONTROL_PUBLISH", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a54f09665c3957a13c6ff55863bc86c06", null ],
      [ "MQTT_CONTROL_PUBACK", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679af0457f2c5906583a9112f3d2c0ccfb59", null ],
      [ "MQTT_CONTROL_PUBREC", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a39c3f450e13d6a1e87b62cf79f96cf83", null ],
      [ "MQTT_CONTROL_PUBREL", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679aa64e17b5247a6b7550739eebf52cb2c9", null ],
      [ "MQTT_CONTROL_PUBCOMP", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679ab2c6c750cb67d721e9e46ce44f69af21", null ],
      [ "MQTT_CONTROL_SUBSCRIBE", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a968375071029f8a1adb627ea3bd175db", null ],
      [ "MQTT_CONTROL_SUBACK", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679ace15e56c302f716980b4235914866e54", null ],
      [ "MQTT_CONTROL_UNSUBSCRIBE", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679aaab242590b4d41018e19f41701be51f3", null ],
      [ "MQTT_CONTROL_UNSUBACK", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a9084892e26432dbface9e5e001fcde16", null ],
      [ "MQTT_CONTROL_PINGREQ", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a1c76fcf01223b8ca5ca7a9a6f255da79", null ],
      [ "MQTT_CONTROL_PINGRESP", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a375c1cc1a6243362c39329506a367c87", null ],
      [ "MQTT_CONTROL_DISCONNECT", "group__unpackers.html#ggacbd36b88ec7f62bc161b07e1a0aed679a8368c077d1056eb3ab600eb6205b9dd4", null ]
    ] ],
    [ "MQTTSubackReturnCodes", "group__unpackers.html#ga2d626b05e589a148ce2e9e97f41302ae", [
      [ "MQTT_SUBACK_SUCCESS_MAX_QOS_0", "group__unpackers.html#gga2d626b05e589a148ce2e9e97f41302aea1bbe099b18a7f0ed878ebb0a60e1210a", null ],
      [ "MQTT_SUBACK_SUCCESS_MAX_QOS_1", "group__unpackers.html#gga2d626b05e589a148ce2e9e97f41302aeadf939e22b959e88c15e3c6bab55967d8", null ],
      [ "MQTT_SUBACK_SUCCESS_MAX_QOS_2", "group__unpackers.html#gga2d626b05e589a148ce2e9e97f41302aea1c6c926f38967dfe73d4ecfbeb495288", null ],
      [ "MQTT_SUBACK_FAILURE", "group__unpackers.html#gga2d626b05e589a148ce2e9e97f41302aea08b9651ef43ea219f29125fcb43952f7", null ]
    ] ],
    [ "mqtt_unpack_connack_response", "group__unpackers.html#gaa174fec8a214d65ee887b5b6c9b79d78", null ],
    [ "mqtt_unpack_fixed_header", "group__unpackers.html#gad596aa5faf7f79e05fb15da33321db10", null ],
    [ "mqtt_unpack_publish_response", "group__unpackers.html#gae8ee6c1da210c4782f4f9939fe6ec828", null ],
    [ "mqtt_unpack_pubxxx_response", "group__unpackers.html#ga8c9b9bb3aab29bfca1408b9e5c5d4a01", null ],
    [ "mqtt_unpack_response", "group__unpackers.html#gaae124a93579dcd31e6f52411f4582fbd", null ]
];