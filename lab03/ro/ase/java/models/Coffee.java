package lab03.ro.ase.java.models;

import java.io.Serializable;

public class Coffee implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String beverageName;
	private String coffeeType;
	private double price;
	
	public Coffee() {}
	
	public Coffee(String name, String type, double price) {
		this.beverageName = name;
		this.coffeeType = type;
		this.price = price;
	}

	public String getBeverageName() {
		return beverageName;
	}

	public void setBeverageName(String beverageName) {
		this.beverageName = beverageName;
	}

	public String getCoffeeType() {
		return coffeeType;
	}

	public void setCoffeeType(String coffeeType) {
		this.coffeeType = coffeeType;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}
	
	

}
