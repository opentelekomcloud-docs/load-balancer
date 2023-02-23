:original_name: elb_ug_jt_060301.html

.. _elb_ug_jt_060301:

Overview
========

Advanced forwarding policies are available only for dedicated load balancers. If you have enabled **Advanced Forwarding**, perform the following operations to add advanced forwarding policies to HTTP and HTTPS listeners of dedicated load balancers.

You can add advanced forwarding policies to HTTP or HTTPS listeners of dedicated load balancers to route requests more specifically.


.. figure:: /_static/images/en-us_image_0000001197097021.png
   :alt: **Figure 1** How advanced forwarding works

   **Figure 1** How advanced forwarding works

#. The client sends a request to the load balancer.
#. The load balancer matches the request based on the forwarding rule you configure.
#. The load balancer forwards the request to the corresponding backend server or returns a fixed response to the client based on the action you configure.
#. The load balancer sends a response to the client.

   -  Each advanced forwarding policy consists of one or more forwarding rules and an action.

      -  Dedicated load balancers support the following types of forwarding rules: domain name, URL, HTTP request method, HTTP header, query string, and CIDR block (source IP addresses). For details, see :ref:`Forwarding Rule Types <elb_ug_jt_060302__en-us_topic_0000001182135225_section1351817374499>`.
      -  There are four types of actions: forward to a backend server group, redirect to another listener, redirect to another URL, and return a specific response body. For details, see :ref:`Action Types <elb_ug_jt_060302__en-us_topic_0000001182135225_section107001685017>`.
