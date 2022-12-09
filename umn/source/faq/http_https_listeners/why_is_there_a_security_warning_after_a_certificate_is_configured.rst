:original_name: elb_faq_0118.html

.. _elb_faq_0118:

Why Is There a Security Warning After a Certificate Is Configured?
==================================================================

The following may cause the Not Secure warning even after a certificate is configured:

-  The domain name used by the certificate is different from the domain name accessed by users. (If this is the case, check the domain name used the certificate to ensure that the domain names are the same or create a self-signed certificate.)
-  SNI is configured, but the specified domain name is different from the one used by the certificate.
-  The domain name level is inconsistent with the certificate level.

If the problem persists, run the **curl** *{Domain name}* command to locate the fault based on the error information returned by the system.
