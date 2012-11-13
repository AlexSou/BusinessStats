

import display.*;

public class Controller {

  public static int Max = 9;
  protected NumberCanvas passengers;
  int pax = 0; //Passengers in platform.


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
	  
	  while(pax < mcar){ //Train not ready to depart.
		  wait();
	  }
	  loadedpax = mcar;  
	  pax = pax - loadedpax;
	  passengers.setValue(pax);
	  notifyAll();
	  return loadedpax; //Passengers that left.
  }

  public void goNow() {

  }

}