:original_name: elb_faq_211003.html

.. _elb_faq_211003:

Why Is Access to Backend Servers Still Abnormal Even If I Have Created a Certificate?
=====================================================================================

The following are possible causes:

-  You have created a certificate on the ELB console, but you do not have an HTTPS listener.

   To solve this problem, perform the following steps:

   -  Continue using the current listener and install the certificate on the backend server.
   -  Delete the current listener, add an HTTPS listener, and bind a certificate to the HTTPS listener.

-  You have created a certificate on the **Certificates** page and are using an HTTPS listener, but you have not bound the certificate to the listener.

-  Your certificate has expired.

-  The domain name is different from the one specified when you create the certificate.

-  A certificate chain is used, but its format is incorrect.
