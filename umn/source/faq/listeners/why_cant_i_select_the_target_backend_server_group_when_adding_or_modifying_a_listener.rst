:original_name: elb_faq_210409.html

.. _elb_faq_210409:

Why Can't I Select the Target Backend Server Group When Adding or Modifying a Listener?
=======================================================================================

The backend server group's protocol (backend protocol) you want to select is not supported by the listener's protocol (frontend protocol). There are some constraints on the backend protocol when you associate a backend server group with a listener.

.. table:: **Table 1** Frontend and backend protocols of dedicated load balancers

   ================= ================
   Frontend Protocol Backend Protocol
   ================= ================
   TCP               TCP
   UDP               UDP/QUIC
   HTTP              HTTP
   HTTPS             HTTP/HTTPS
   ================= ================

.. table:: **Table 2** Frontend and backend protocols of shared load balancers

   ================= ================
   Frontend Protocol Backend Protocol
   ================= ================
   TCP               TCP
   UDP               UDP
   HTTP              HTTP
   HTTPS             HTTP
   ================= ================
