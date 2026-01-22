
class Room {
	int height, breadth, width;
	Room(int x, int y, int z) {
		height = x;
		width = y;
		breadth = z;
	}
	int volume() {
		System.out.println("Height is " + height + ", Width is " + width + ", breadth is " + breadth);
		return (height*width*breadth);
	}
}
	
class RoomDemo {
	public static void main(String args[]) {
		Room r1 = new Room(10, 5, 5);
		System.out.println("Volume is " + r1.volume());
	}
}
