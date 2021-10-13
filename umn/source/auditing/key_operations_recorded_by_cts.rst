Key Operations Recorded by CTS
==============================

You can use CTS to record operations on ELB for query, auditing, and backtracking.

`Table 1 <#elb_ug_sj_0001__table1419082716297>`__ lists the operations recorded by CTS.



.. _elb_ug_sj_0001__table1419082716297:

.. table:: **Table 1** ELB operations recorded by CTS

   ================================ ============= ===========================
   Action                           Resource Type Trace
   ================================ ============= ===========================
   Configuring access logs          accesslog     create access log
   Deleting access logs             accesslog     delete access log
   Creating a certificate           certificate   create certificate
   Modifying a certificate          certificate   update certificate
   Deleting a certificate           certificate   delete certificate
   Creating a health check          healthmonitor create healthmonitor
   Modifying a health check         healthmonitor update healthmonitor
   Deleting a health check          healthmonitor delete healthmonitor
   Adding a forwarding policy       l7policy      create forwarding policy
   Modifying a forwarding policy    l7policy      update forwarding policy
   Deleting a forwarding policy     l7policy      delete forwarding policy
   Adding a forwarding rule         l7rule        create forwarding rule
   Modifying a forwarding rule      l7rule        update forwarding rule
   Deleting a forwarding rule       l7rule        delete forwarding rule
   Adding a listener                listener      create listener
   Modifying a listener             listener      update listener
   Deleting a listener              listener      delete listener
   Creating a load balancer         loadbalancer  create loadbalancer
   Modifying a load balancer        loadbalancer  update loadbalancer
   Deleting a load balancer         loadbalancer  delete loadbalancer
   Adding a backend server          member        add backend ecs
   Modifying a backend server       member        update backend ecs
   Removing a backend server        member        remove backend ecs
   Creating a backend server group  pool          create backend member group
   Modifying a backend server group pool          update backend member group
   Deleting a backend server group  pool          delete backend member group
   ================================ ============= ===========================
