This sketch was created to receive arduino messages from an Xbee in DigiMesh Transparent mode.

It can also be used to read any Serial port.

Due to its simplicity it was preferred not to use Interrupts, although it was planned to be

If you send a message you must include the Newline in your message (\n), if you create a hexadecimal message it would be (A0) in the last characters.
