:original_name: elb_faq_210804.html

.. _elb_faq_210804:

Why Is a Forwarding Policy in the Faulty State?
===============================================

A possible cause is that you added a forwarding policy that is the same as an existing one. Even if you delete the existing forwarding policy, the newly-added forwarding policy is still faulty.

To resolve this issue, delete the newly-added forwarding policy and add a different one.
