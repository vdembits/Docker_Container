FROM gcc:latest

 COPY . /usr/src/BigInteger

 WORKDIR /usr/src/BigInteger

 RUN g++ -std=c++17 *.cpp -o BigInteger

 CMD [ "./BigInteger" ]