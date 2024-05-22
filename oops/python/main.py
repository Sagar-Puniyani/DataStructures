class Car:
    def __init__(self ,brand , model ) :
        self.__brand = brand
        self.model = model

    def getFullname(self):
        print(f"{self.model} - {self.__brand}")
    
    def get_brand(self):
        print(f"{self.__brand}")


class ElectricCar(Car):
    def __init__(self ,brand , model , batterysize):
        super().__init__(brand , model)
        self.batterysize = batterysize




# mycar = Car("Toyota" , "xyz")
# print(mycar)
# print(mycar.model)
# print(mycar.brand)
# mycar.getFullname()

my_tesla = ElectricCar("Tesla" , "Model S" , "85kWH")
print(my_tesla)
print(my_tesla.model)
# print(my_tesla.brand)
my_tesla.getFullname()
my_tesla.get_brand()


