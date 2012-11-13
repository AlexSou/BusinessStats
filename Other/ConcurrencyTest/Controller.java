
import display.*;

public class Controller {

  public static int Max = 9;
  protected NumberCanvas passengers;
  int pax = 0; //Passengers in platform.
  boolean gonow = false;


  public Controller(NumberCanvas nc) {
    passengers = nc;
  }

  public synchronized void newPassenger() throws InterruptedException {

	  while (pax == Max) wait(); //Too many passengers waiting, wait.
		  pax++; 
		  passengers.setValue(pax);
		  notifyAll();
	  
  }

  public  synchronized int getPassengers(int mcar) throws InterruptedException {

	  int loadedpax = 0; //Passengers in train.
	  
	  while(pax < mcar && !(gonow)){ //Train not ready to depart.
		  wait();
	  }
	  
	  if(gonow) { //Load all passengers and leave now.
		  loadedpax = pax;  
	  }
	  else{ 
		  loadedpax = mcar;  
	  }
	  
	  pax = pax - loadedpax;
	  passengers.setValue(pax);
	  gonow = false;
	  notifyAll();
	  return loadedpax; //Passengers that left.
  }

  public synchronized void goNow() {
    
	  if (pax == 0) return; // No people, abort,
	  gonow = true;
	  notifyAll(); //Notify all threads to resume them.
  }

}