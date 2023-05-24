:original_name: elb_faq_211004.html

.. _elb_faq_211004:

Will the Network or Load Balancing Be Interrupted When a Certificate Is Being Replaced?
=======================================================================================

No.

The new certificate takes effect immediately after the replacement. The old certificate is used for established connections, and the new one is used for new connections.

.. note::

   When the certificate expires, the system displays a message indicating that the connection is insecure. However, you can ignore the warning and continue accessing the website.
