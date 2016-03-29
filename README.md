# ecs501Uminiproject
ECS501U - C Porgramming miniproject

Code I wrote for the C programming miniproject. To compile and execute refer to user guide.

#Specifications

1.  Design Brief – CORE Task [50 marks]
The aim is to design and implement software (written in the C program ming language) that simulates an imaginary simple type of router

1.1. Router functionality
The purpose of the router is to process packets arriving on its input queues and to place each packet in the appropriate output queue, based on its layer 3 destination address. The router can be connected to 5 other device, and so it has 5 input queues and 5 output queues
The functionality of the router includes:
A ‘round‐robin’ like scheduling scheme1 , which is used to multiplex the input queue ’ traffic. 
A simple form of ‘load balancing’ on its output queues, i.e. if there are multiple destination routes for a packet, then the packet is queued in one of the valid output queues randomly. Input queues, which should have a configurable maximum length.
Output queues, which should have a configurable maximum length. 
The main queue in the router, which multiplexes all the packets arriving on the input queues – this queue should also have a configurable maximum length. 

The router application will also need to define the structure of: 
network layer 2 packets, which consist of,
  -  source address, represented by a character;
  -	destination address, represented by a character; 
  -	payload, represented by an array of characters; 
network layer 3 packets which are extracted from layer 2 packets arriving at the router; their structure is as follows: 
  -	source address, represented by an integer value; 
  - destination address, represented by an integer value; 
  - priority field, represented by an integer value;
  - payload, represented by an array of characters;


