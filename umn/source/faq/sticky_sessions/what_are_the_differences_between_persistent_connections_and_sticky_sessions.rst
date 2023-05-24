:original_name: elb_faq_0126.html

.. _elb_faq_0126:

What Are the Differences Between Persistent Connections and Sticky Sessions?
============================================================================

Persistent connections are not necessarily related to sticky sessions.

A persistent connection allows multiple data packets to be sent continuously over a TCP connection. If no data packets are sent over the connection, the client and the server need to send link detection packets to each other. Sticky sessions enable all requests from the same client during one session to be sent to the same backend server.
