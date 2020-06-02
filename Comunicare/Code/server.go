package main

import (
	"fmt"
	"log"
	"net/http"
	"github.com/gorilla/mux"
	"io/ioutil"
	"encoding/json"
)

type telemetry struct {
	Temperature  float32   `json:"temperature"`
	Humidity     float32   `json:"humidity"`
	Light        float32   `json:"light"`
}

func addMessage(w http.ResponseWriter, r *http.Request) {
	var newMsg telemetry
	reqBody, err := ioutil.ReadAll(r.Body)
	if err != nil {
		fmt.Fprintf(w, "Error!")
	}

	msg := string(reqBody)
	fmt.Println(msg)

	json.Unmarshal(reqBody, &newMsg)

	fmt.Printf("Temperature = %2.2f\n", newMsg.Temperature)


	if (newMsg.Temperature > 30) {
		w.Write([]byte("ALARM!"))
	} else {
		w.Write([]byte("OK"))
	}

}


func main() {
	router := mux.NewRouter().StrictSlash(true)
	router.HandleFunc("/message", addMessage).Methods("POST")
	fmt.Println("Server started on port 7070")
	log.Fatal(http.ListenAndServe(":7070", router))
}