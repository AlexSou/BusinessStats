

public class PlatformAccess {

  
  boolean platocc = false; //Platform is occupied 

  public synchronized void arrive() throws InterruptedException {
    
	  while (platocc) wait(); //Train is platform, wait.
	  platocc = true;  //Use platform
	  notifyAll();     //Notify that platform is occupied.
  }

  public synchronized void depart() {
    
	  platocc = false; //Platform is free.
	  notifyAll();  //Notify that platform is free.
	  
  }

}